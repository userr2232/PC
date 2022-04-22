class Solution {
    bool validPalindrome(int i, int j, const string& s, bool deleted) {
        while(i < j) {
            if(s[i] == s[j]) i++, j--;
            else if(deleted) return false;
            else return validPalindrome(i+1, j, s, true) || validPalindrome(i, j-1, s, true);
        }
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        const int n = s.length();
        return validPalindrome(0, n-1, s, false);
    }
};