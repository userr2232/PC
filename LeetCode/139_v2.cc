class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> explored(s.length()+1, false);
        q.push(0);
        explored[0] = true;
        while(!q.empty()) {
            int start = q.front();
            q.pop();
            for(int end = start+1; end <= s.length(); ++end) if(!explored[end]) {
                string current = s.substr(start, end-start);
                if(dict.count(current)) {
                    explored[end] = true;
                    q.push(end);
                    if(end == s.length()) return true;
                }
            }
        }
        return false;
    }
};