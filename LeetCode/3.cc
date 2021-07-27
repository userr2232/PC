class Solution {
public:
    int ord(char c) {
        return c;
    }
    
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256, -1);
        int mx{0}, start{0};
        for(int i = 0; i < s.length(); ++i) {
            int ci = ord(s[i]);
            if(pos[ci] == -1) pos[ci] = i;
            else {
                for(int j = start; j < pos[ci]; ++j) { pos[ord(s[j])] = -1; }
                start = pos[ci]+1;
                pos[ci] = i;
            }
            mx = max(mx, i-start+1);
        }
        return mx;
    }
};