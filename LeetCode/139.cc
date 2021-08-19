class Solution {
    unordered_set<string> dict;
    vector<int> memo;
    string str;
    
    int dp(int start) {
        if(start < str.length()) {
            int& ans = memo[start];
            if(ans != -1) return ans;
            for(int len = str.length()-start; len >= 1; --len) {
                string current = str.substr(start, len);
                if(dict.count(current) && dp(start+len)) return ans = 1;
            }
            return ans = 0;
        }
        return 1;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        str = s;
        memo.assign(n+1, -1);
        for(const auto& word : wordDict) dict.insert(word);
        return dp(0) == 1;
    }
};