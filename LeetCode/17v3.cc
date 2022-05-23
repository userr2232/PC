class Solution {
    unordered_map<char,vector<char>> keyboard;
    
    void generate(vector<string>& ans, string const& digits, int i = 0, vector<char>&& current = {}) {
        if(i == digits.length()) {
            if(!current.empty()) ans.emplace_back(current.begin(), current.end());
            return;
        }
        for(auto&& c : keyboard[digits[i]]) {
            current.emplace_back(c);
            generate(ans, digits, i+1, forward<vector<char>>(current));
            current.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        char c = 'a';
        for(int i = 2; i <= 9; ++i) {
            int max_j = i == 7 || i == 9 ? 4 : 3;
            for(int j = 0; j < max_j; ++j) {
                keyboard['0'+i].emplace_back(c++);
            }
        }
        generate(ans, digits);
        return ans;
    }
};