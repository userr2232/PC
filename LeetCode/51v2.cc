class Solution {
    bool valid(int i, int j, vector<int> const& current) {
        for(int k = 0; k < current.size(); ++k)
            if(i + j == k + current[k] || i - j == k - current[k]) 
                return false;
        return true;
    }
    
    void generate(vector<vector<string>>& ans, vector<bool>& taken, vector<int>&& current = {}, int i = 0) {
        if(i == taken.size()) {
            ans.emplace_back();
            string str(taken.size(), '.');
            for(auto&& e : current) {
                str[e] = 'Q';
                ans.back().emplace_back(str);
                str[e] = '.';
            }
            return;
        }
        for(int j = 0; j < taken.size(); ++j) if(!taken[j] && valid(i, j, current)) {
            taken[j] = true;
            current.emplace_back(j);
            generate(ans, taken, forward<vector<int>>(current), i+1);
            current.pop_back();
            taken[j] = false;
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> taken(n, false);
        generate(ans, taken);
        return ans;
    }
};