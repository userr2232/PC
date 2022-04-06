class Solution {
    int m, n;
    vector<vector<vector<bool>>> visited;
    
    bool valid(int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    
    void dfs(int i, int j, int ocean, const vector<vector<int>>& heights) {
        visited[i][j][ocean] = true;
        for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) if(abs(di) != abs(dj)) {
            int new_i{i+di}, new_j{j+dj};
            if(!valid(new_i, new_j) || heights[new_i][new_j] < heights[i][j]) continue;
            if(!visited[new_i][new_j][ocean]) 
                dfs(new_i, new_j, ocean, heights);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        visited.assign(m, vector<vector<bool>>(n, vector<bool>(2, false)));
        for(int i = 0; i < m; ++i) {
            if(!visited[i][0][0]) dfs(i, 0, 0, heights);
            if(!visited[i][n-1][1]) dfs(i, n-1, 1, heights);
        }
        for(int i = 0; i < n; ++i) {
            if(!visited[0][i][0]) dfs(0, i, 0, heights);
            if(!visited[m-1][i][1]) dfs(m-1, i, 1, heights);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) {
            if(visited[i][j][0] && visited[i][j][1]) 
                ans.push_back({i, j});
        }
        return ans;
    }
};