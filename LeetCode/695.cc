class Solution {
    int m, n;
    
    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    int dfs(int i, int j, vector<vector<int>> const& grid, vector<vector<bool>>& visited) {
        int size{1};
        visited[i][j] = true;
        for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) if(abs(di) != abs(dj)) {
            int new_i{i+di}, new_j{j+dj};
            if(!valid(new_i, new_j) || grid[new_i][new_j] == 0 || visited[new_i][new_j]) continue;
            size += dfs(new_i, new_j, grid, visited);
        }
        return size;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int max_area{0};
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) if(grid[i][j] == 1 && !visited[i][j]) {
            max_area = max(max_area, dfs(i, j, grid, visited));
        }
        return max_area;
    }
};