class Solution {
    int start{0}, longest{1};
    
    void expand(int i, int length, const string& s) {
        int j = i+length-1;
        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            if(longest < length) {
                start = i;
                longest = length;
            }
            i--, j++;
            length += 2;
        }
    }
    
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        for(int i = n; i >= 0; --i) {
            expand(i, 1, s);
            if(i) expand(i-1, 2, s);
        }
        return s.substr(start, longest);
    }
};