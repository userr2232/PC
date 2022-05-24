class Solution {
    int m, n;
    
    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    int bfs(queue<pair<int,int>>& q, vector<vector<int>> const& grid, vector<vector<bool>>& visited) {
        int minutes{0};
        while(!q.empty()) {
            int size = q.size();
            for(int k = 0; k < size; ++k) {
                auto [i, j] = q.front();
                q.pop();
                visited[i][j] = true;
                for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) if(abs(di) != abs(dj)) {
                    int new_i{i+di}, new_j{j+dj};
                    if(!valid(new_i, new_j) || grid[new_i][new_j] != 1 || visited[new_i][new_j]) continue;
                    q.emplace(new_i, new_j);
                    visited[new_i][new_j] = true;
                }
            }
            if(!q.empty()) minutes++;
        }
        return minutes;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) if(grid[i][j] == 2)
            q.emplace(i, j);
        int min_minutes = bfs(q, grid, visited);
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j)
            if(grid[i][j] == 1 && !visited[i][j]) return -1;
        return min_minutes;
    }
};