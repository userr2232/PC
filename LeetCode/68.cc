class Solution {
    vector<string> print_lines(const vector<pair<int,int>>& word_num_length, const vector<string>& words, const int& maxWidth) {
        vector<string> ans;
        int j{0};
        for(int i = 0; i < word_num_length.size(); ++i) {
            auto [words_num, words_length] = word_num_length[i];
            int space_remaining = maxWidth - words_length;
            ans.emplace_back();
            for(int k = 0; k < words_num; ++k) {
                ans.back() += words[j++];
                if(i+1 == word_num_length.size()) {
                    if(space_remaining)
                        ans.back() += ' ', space_remaining--;
                }
                else {
                    int space = k+1 < words_num ? ceil(static_cast<double>(space_remaining)/(words_num-k-1)) : space_remaining;
                    space_remaining -= space;
                    ans.back() += string(space, ' ');
                }
            }
            ans.back() += string(space_remaining, ' ');
        }
        return ans;
    }
    
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<pair<int,int>> word_num_length;
        int line_length{0};
        for(auto&& word : words) {
            auto&& word_length = word.length();
            if(line_length == 0) {
                line_length = word_length;
                word_num_length.emplace_back(1, word_length);
            }
            else if(line_length + 1 + word_length <= maxWidth) {
                line_length += 1 + word_length;
                auto&& back = word_num_length.back();
                back.first++, back.second += word_length;
            }
            else {
                line_length = word_length;
                word_num_length.emplace_back(1, word_length);
            }
        }
        return print_lines(word_num_length, words, maxWidth);
    }
};