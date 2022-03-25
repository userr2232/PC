class Solution {
    vector<vector<bool>> rows, cols, boxes;
    
    bool solveSudoku(vector<vector<char>>& board, int i, int j) {
        if(i == 9) return true;
        int start_i{i}, start_j{j};
        for(; i < 9; ++i) {
            bool b = false;
            j = start_i == i ? start_j : 0;
            for(; j < 9 && !b; ++j) {
                if(board[i][j] == '.') {
                    b = true;
                    break;
                }
            }
            if(b) break;
        }
        if(i == 9) return true;
        for(int num = 1; num <= 9; ++num) {
            int idx = num-1;
            if(rows[i][idx] || cols[j][idx] || boxes[3*(i/3)+j/3][idx]) continue;
            rows[i][idx] = cols[j][idx] = boxes[3*(i/3)+j/3][idx] = true;
            board[i][j] = static_cast<char>('0'+num);
            if(solveSudoku(board, j < 8 ? i : i+1, j < 8 ? j+1 : 0)) 
                return true;
            rows[i][idx] = cols[j][idx] = boxes[3*(i/3)+j/3][idx] = false;
            board[i][j] = '.';
        }
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.assign(9, vector<bool>(9, false));
        cols.assign(9, vector<bool>(9, false));
        boxes.assign(9, vector<bool>(9, false));
        for(int i = 0; i < 9; ++i) for(int j = 0; j < 9; ++j) {
            if(isdigit(board[i][j])) {
                int num = static_cast<int>(board[i][j]-'0');
                int idx = num-1;
                rows[i][idx] = cols[j][idx] = boxes[3*(i/3)+j/3][idx] = true;
            }
        }
        solveSudoku(board, 0, 0);
    }
};