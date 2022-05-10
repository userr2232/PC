class Solution {
    
    bool validate_line(vector<vector<char>> const& board, int i, int j, int di, int dj) {
        vector<bool> v(9, false);
        for(int k = 0; k < 9; ++k) if(auto&& cell = board[i+k*di][j+k*dj]; isdigit(cell)) {
            int val = cell-'0';
            if(v[val-1]) return false;
            else v[val-1] = true;
        }
        return true;
    }
    
    bool validate_columns(vector<vector<char>> const& board) {
        for(int j = 0; j < 9; ++j)
            if(!validate_line(board, 0, j, 1, 0)) return false;
        return true;
    }
    
    bool validate_rows(vector<vector<char>> const& board) {
        for(int i = 0; i < 9; ++i)
            if(!validate_line(board, i, 0, 0, 1)) return false;
        return true;
    }
    
    bool validate_boxes(vector<vector<char>> const& board) {
        for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) {
            int xi{3*i}, xj{3*j};
            vector<bool> v(9, false);
            for(int k = xi; k < xi+3; ++k) for(int l = xj; l < xj+3; ++l) if(auto&& cell = board[k][l]; isdigit(cell)) {
                int val = cell-'0';
                if(v[val-1]) return false;
                else v[val-1] = true;
            }
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return validate_rows(board) && validate_columns(board) && validate_boxes(board);
    }
};