class Solution {
    int mx{0}, optim_i{0}, n;
    string s;
    
    void expand(int i, int j) {
        int len{0};
        while(i >= 0 && j < n) {
            if(s[i] == s[j]) {
                len = j-i+1;
                if(len > mx) mx = len, optim_i = i;
                --i, ++j;
            }
            else break;
        }
    }
    
public:
    string longestPalindrome(string s) {
        n = s.length(), this->s = s;
        for(int i = 0; i < n; ++i) {
            expand(i, i);
            if(i) expand(i-1, i);
        }
        return s.substr(optim_i, mx);
    }
};