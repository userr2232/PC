class Solution {
    int count{0};
    
    void expand(int i, int length, const string& s) {
        int j = i + length - 1;
        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            count++;
            i--, ++j;
        }
    }
    
public:
    int countSubstrings(string s) {
        const int n = s.length();
        for(int i = n; i >= 0; --i) {
            expand(i, 1, s);
            if(i) expand(i-1, 2, s);
        }
        return count;
    }
};