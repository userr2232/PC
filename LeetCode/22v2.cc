class Solution {
    void generate(vector<string>& v, int const& n, vector<char>&& str = {}, int open = 0) {
        if(str.size() == n << 1) {
            if(open == 0) v.emplace_back(str.begin(), str.end());
            return ;
        }
        if(open) {
            str.emplace_back(')');
            generate(v, n, forward<vector<char>>(str), open-1);
            str.pop_back();
        }
        str.emplace_back('(');
        generate(v, n, forward<vector<char>>(str), open+1);
        str.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, n);
        return ans;
    }
};