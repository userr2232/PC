class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans, mark{0};
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<pair<int,int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) if(grid[i][j] == 1) {
            vector<pair<int,int>> bfs(1, {j, i}), bfs2;
            int level{0};
            ans = INT_MAX;
            while(!bfs.empty()) {
                ++level;
                for(const auto [x, y] : bfs) {
                    for(const auto [dx, dy] : d) {
                        int nx{x+dx}, ny{y+dy};
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[ny][nx] == mark) {
                            dist[ny][nx] += level;
                            --grid[ny][nx];
                            ans = min(ans, dist[ny][nx]);
                            bfs2.emplace_back(nx, ny);
                        }
                    }
                    if(ans == INT_MAX) return -1;
                }
                swap(bfs, bfs2);
                bfs2.clear();
            }
            --mark;
        }
        return ans;
    }
};