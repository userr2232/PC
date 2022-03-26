class Solution {
    vector<vector<vector<int>>> memo;
    
    int dp(int i, int b, int count, const string& str) {
        if(i == str.length()) return count;
        int& ans = memo[i][b][count];
        if(ans != -1) return ans;
        int max_digit = b ? static_cast<int>(str[i]-'0') : 9;
        ans = 0;
        for(int digit = 0; digit <= max_digit; ++digit)
            ans += dp(i+1, b && digit == max_digit, count + (digit == 1), str);
        return ans;
    }
    
public:
    int countDigitOne(int n) {
        string str = to_string(n);
        const int l = str.length();
        memo.assign(l, vector<vector<int>>(2, vector<int>(12, -1)));
        return dp(0, 1, 0, str);
    }
};