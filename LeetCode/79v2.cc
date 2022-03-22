class Solution {
    int m, n;
    vector<vector<bool>> visited;
    
    bool valid(int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    
    bool dfs(int i, int j, int k, const vector<vector<char>>& board, const string& word) {
        visited[i][j] = true;
        if(word[k] == board[i][j]) {
            if(k == word.length()-1) return true;
            for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) if(abs(di) != abs(dj)) {
                int new_i{i+di}, new_j{j+dj};
                if(!valid(new_i, new_j)) continue;
                if(!visited[new_i][new_j]) {
                    if(dfs(new_i, new_j, k+1, board, word)) return true;
                }
            }
        }
        visited[i][j] = false;
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        visited.assign(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j)
            if(dfs(i, j, 0, board, word)) return true;
        return false;
    }
};