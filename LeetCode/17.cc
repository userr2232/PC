class Solution {
    unordered_map<int,string> number_letter;
public:
    void generate(vector<string>& ans, string& str, const string& digits, const int& id = 0) {
        if(id == digits.length() && str.length()) {
            ans.push_back(str);
            return;
        }
        int n = str.length();
        for(const char& c : number_letter[digits[id]-'0']) {
            str += c;
            generate(ans, str, digits, id+1);
            str = str.substr(0, n);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        char cur = 'a';
        int k = 0;
        for(int i = 2; i <= 9; ++i) for(int j = 0; j < (i == 7 || i == 9 ? 4 : 3); ++j) {
            number_letter[i] += (char)(cur + k++);
        }
        vector<string> ans;
        string tmp = "";
        generate(ans, tmp, digits);
        return ans;
    }
};