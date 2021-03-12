class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> memo(n, vector<bool>(n, false));
        auto answer = 0;
        for(int i = 0; i < n; ++i) {
            memo[i][i] = true;
            answer += 1;
            if(i < n - 1 && s[i] == s[i+1]) {
                memo[i][i+1] = true;
                answer += 1;
            }
        }
        for(int i = n - 2; i >= 0; --i) {
            for(int j = i + 1; j < n; ++j) {
                if(memo[i+1][j-1] && s[i] == s[j]) {
                    answer += memo[i][j] = 1;
                }
            }
        }
        return answer;
    }
};