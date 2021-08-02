class Solution {
    vector<vector<int>> dfs_num;
    bool valid(int i, int j) {
        return !((i >= m || i < 0) || (j >= n || j < 0));
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid) {
        dfs_num[i][j] = EXPLORED;
        for(int l = -1; l <= 1; ++l) for(int k = -1; k <= 1; ++k) if(abs(k) != abs(l) && valid(i+l, j+k) && grid[i+l][j+k] == '1' && !dfs_num[i+l][j+k]) {
            dfs(i+l,j+k,grid);
        }
        dfs_num[i][j] = VISITED;
    }
    
    int numberOfComponents{0}, m{0}, n{0};
    const int UNVISITED = 0;
    const int EXPLORED = 1;
    const int VISITED = 2;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dfs_num.assign(grid.size(), vector<int>(grid[0].size(), UNVISITED));
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) if(grid[i][j] == '1' && !dfs_num[i][j]) {
            numberOfComponents++; dfs(i, j, grid);
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) cout << dfs_num[i][j] << " ";
            cout << endl;
        }
        return numberOfComponents;
    }
};