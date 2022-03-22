const int INF = 1e9;
class Solution {
    vector<vector<int>> memo;
    
    int dp(int i, int K, const string& s) {
        if(i+K >= s.length()) return 0;
        int& ans = memo[i][K];
        if(ans != INF) return ans;
        if(K) ans = dp(i+1, K-1, s);
        int k{K}, count{1};
        for(int j = i+1; j <= s.length(); ++j) {
            ans = min(ans, dp(j, k, s) + 1 + (count >= 100 ? 3 : count >= 10 ? 2 : count >= 2 ? 1 : 0));
            if(s[j] == s[i]) count++;
            else if(--k < 0) break;
        }
        return ans;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        const int n = s.length();
        memo.assign(n, vector<int>(k+1, INF));
        return dp(0, k, s);
    }
};