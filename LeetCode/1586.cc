class Solution {
    vector<vector<int>> dist, visited;
    int m, n;
    
    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    void bfs(int i, int j, const int building, vector<vector<int>> const& grid) {
        queue<pair<int,int>> q;
        q.emplace(i, j);
        int d{0};
        while(!q.empty()) {
            int size = q.size();
            d++;
            for(int k = 0; k < size; ++k) {
                auto [i, j] = q.front();
                q.pop();
                for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) if(abs(di) != abs(dj)) {
                    int new_i{i+di}, new_j{j+dj};
                    if(!valid(new_i, new_j) || grid[new_i][new_j] != 0 || visited[new_i][new_j] != building-1)
                        continue;
                    visited[new_i][new_j] = building;
                    dist[new_i][new_j] += d;
                    q.emplace(new_i, new_j);
                }
            }
        }
    }
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return -1;
        m = grid.size(), n = grid[0].size();
        dist.assign(m, vector<int>(n, 0));
        visited.assign(m, vector<int>(n, -1));
        int building{0};
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) 
            if(grid[i][j] == 1)
                bfs(i, j, building++, grid);
        int ans = 2e9;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            if(visited[i][j] == building-1)
                ans = min(ans, dist[i][j]);
        return ans == 2e9 ? -1 : ans;
    }
};