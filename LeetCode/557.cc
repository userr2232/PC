class Solution {
public:
    string reverseWords(string s) {
        int i{0}, j{0};
        while(j+1 < s.size()) {
            i = j;
            if(i >= s.size()) break;
            while(i+1 < s.size() && s[i] == ' ') ++i;
            j = i;
            while(j < s.size() && s[j] != ' ') ++j;
            reverse(s.begin()+i, s.begin()+j);
        }
        return s;
    }
};