class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        if(i >= j) return true;
        while(i < j) {
            if(s[i] == s[j]) ++i, --j;
            else return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i{0}, j = s.length() - 1;
        while(i < j) {
            if(s[i] == s[j]) ++i, --j;
            else {
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
    }
};