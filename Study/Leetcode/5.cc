class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> v(n, vector<bool>(n, false));
        int longest{0}, start{0};
        for(int i = 0; i < n; ++i) v[i][i] = true, longest = 1;
        for(int i = n-1; i >= 0; --i) for(int j = i+1; j < n; ++j) {
            v[i][j] = j == i+1 ? s[i] == s[j] : (s[i] == s[j] && v[i+1][j-1]);
            if(v[i][j] && j-i+1 > longest) {
                longest = j-i+1;
                start = i;
            }
        }
        return s.substr(start,longest);
    }
};