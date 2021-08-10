class Solution {
public:
    void expand(const string& s, int left, int right, int& longest, int& start) {
        int n = s.length();
        if(right == n || s[left] != s[right]) return;
        while(right < n-1 && s[right] == s[right+1]) right++;
        while(left > 0 && right < n-1 && s[left-1] == s[right+1]) left--, right++;
        if(right-left+1 > longest) {
            longest = right-left+1;
            start = left;
        }
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        int longest{0}, start{0};
        for(int i = 0; i < n; ++i) {
            expand(s,i,i,longest,start);
            expand(s,i,i+1,longest,start);
        }
        return s.substr(start, longest);
    }
};