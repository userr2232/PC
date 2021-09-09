class Solution {
    int rows, cols;
    vector<vector<bool>> visited;
    
    bool valid(int pos, int delta, int m) {
        int x = pos+delta;
        return x >= 0 && x < m;
    }
    
public:
    bool exist(vector<vector<char>>& board, const string& word, int idx = 0, int row = -1, int col = -1) {
        if(row == -1 && col == -1) {
            rows = board.size();
            if(board.size() == 0) {
                if(word.size()) return false;
                return true;
            }
            cols = board[0].size();
            visited.assign(board.size(), vector<bool>(board[0].size(), false));
            for(int r = 0; r < rows; ++r) for(int c = 0; c < cols; ++c) if(word[idx] == board[r][c]) {
                if(idx < word.size()-1) {
                    visited[r][c] = true;
                    if(exist(board, word, idx+1, r, c)) return true;
                    visited[r][c] = false;
                }
                else return true;
            }
        }
        for(int i = -1; i <= 1; ++i) for(int j = -1; j <= 1; ++j) if(abs(i) != abs(j) && valid(row, i, rows) && valid(col, j, cols) && !visited[row+i][col+j] && board[row+i][col+j] == word[idx]) {
            if(idx < word.size()-1) {
                visited[row+i][col+j] = true;
                if(exist(board, word, idx+1, row+i, col+j)) return true;
                visited[row+i][col+j] = false;
            }
            else return true;
        }
        return false;
    }
};