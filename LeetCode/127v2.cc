class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> uset(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ans{1};
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string u = q.front();
                q.pop();
                if(u == endWord) return ans;
                for(int i = 0; i < u.size(); ++i) {
                    char original = u[i];
                    for(char c = 'a'; c <= 'z'; ++c) if(c != u[i]) {
                        u[i] = c;
                        if(uset.find(u) != uset.end()) {
                            q.push(u);
                            uset.erase(u);
                        }
                        u[i] = original;
                    }
                }
            }
            ++ans;
        }
        return 0;
    }
};