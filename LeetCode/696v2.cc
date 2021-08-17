class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans{0}, prev{0}, current{1};
        for(int i = 1; i < s.length(); ++i) {
            if(s[i] != s[i-1]) {
                ans += min(prev, current);
                prev = current;
                current = 1;
            }
            else current++;
        }
        return ans + min(prev, current);
    }
};