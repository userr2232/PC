class Solution {
    int count(const string& s, int idx) {
        int i{idx-1}, j{idx}, n = s.length();
        char left = s[i], right = s[j];
        while(i-1 >= 0 && j+1 < n && s[i-1] == left && s[j+1] == right) --i, ++j;
        return j-idx+1;
    }
    
public:
    int countBinarySubstrings(string s) {
        int ans{0};
        for(int i = 1; i < s.length(); ++i) if(s[i] != s[i-1]) ans += count(s, i);
        return ans;
    }
};