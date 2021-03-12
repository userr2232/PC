class Solution {
public:
    int dim;
    vector<int> pos;
    vector<vector<string>> result;
    
    void add_result() {
        vector<string> res(dim, string(dim, '.'));
        for(int i = 0; i < dim; ++i)
            res[i][pos[i]] = 'Q';
        result.push_back(res);
    }
    
    bool valid() {
        int just_added = pos.size() - 1;
        for(int i = 0; i < just_added; ++i) {
            auto diff = abs(pos[just_added] - pos[i]);
            if(diff == 0 || diff == just_added - i) return false;
        }
        return true;
    }
    
    void compute(int row) {
        if(row == dim)
            add_result();
        else {
            for(int i = 0; i < dim; ++i) {
                pos.push_back(i);
                if(valid()) 
                    compute(row + 1);
                pos.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        dim = n;
        compute(0);
        return result;
    }
};