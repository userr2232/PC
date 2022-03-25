class Solution {
    vector<string> ans;
    string current;
    
    unordered_map<int, string> m = {
        {2, "abc"}, {3, "def"}, {4, "ghi"},
        {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
        {8, "tuv"}, {9, "wxyz"}
    };
    
    void cartesian_product(int i, const string& digits) {
        if(i == digits.length()) {
            if(current != "") ans.emplace_back(current);
            return;
        }
        string str = m[digits[i]-'0'];
        for(auto c : str) {
            current += c;
            cartesian_product(i+1, digits);
            current = current.substr(0, i);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        cartesian_product(0, digits);
        return ans;
    }
};