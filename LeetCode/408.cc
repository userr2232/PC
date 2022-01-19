class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int j{-1}, len{0};
        for(int i = 0; i < abbr.length(); ++i) {
            char c = abbr[i];
            if(!isdigit(c)) {
                if(++j >= word.length() || word[j] != abbr[i]) return false;
            }
            else {
                int l = c-'0';
                if(len == 0 && l == 0) return false;
                len *= 10;
                len += l;
                if(i == abbr.length()-1 || !isdigit(abbr[i+1])) {
                    j += len;
                    if(j >= word.length()) return false;
                    len = 0;
                }
            }
        }
        return j == word.length()-1;
    }
};