class Solution {    
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        vector<char>::iterator word_start{s.begin()}, word_end{s.begin()};
        while(word_start != s.end()) {
            while(word_end != s.end() && *word_end != ' ') word_end++;
            reverse(word_start, word_end);
            word_start = word_end;
            if(word_start != s.end()) word_start++, word_end++;
        }
    }
};