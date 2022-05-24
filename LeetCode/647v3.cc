class Solution {
    int expand(int i, int j, string const& s) {
        int num{0};
        while(i >= 0 && j < s.length()) {
            if(s[i--] == s[j++]) num++;
            else break;
        }
        return num;
    }
public:
    int countSubstrings(string s) {
        const int n = s.length();
        int ans{0};
        for(int i = 0; i < n; ++i) {
            ans += expand(i, i, s);
            if(i) ans += expand(i-1, i, s);
        }
        return ans;
    }
};