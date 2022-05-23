class Solution {
    static const int PACIFIC = 1;
    static const int ATLANTIC = 2;
    int m, n;
    
    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    void dfs(int i, int j, vector<vector<int>> const& heights, vector<vector<int>>& visited, int VISIT = PACIFIC) {
        visited[i][j] += VISIT;
        for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) if(abs(di) != abs(dj)) {
            int new_i{i+di}, new_j{j+dj};
            if(!valid(new_i, new_j) || visited[new_i][new_j] >= VISIT || heights[new_i][new_j] < heights[i][j])
                continue;
            dfs(new_i, new_j, heights, visited, VISIT);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()) return {};
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) if(visited[i][0] < PACIFIC)
            dfs(i, 0, heights, visited);
        for(int j = 0; j < n; ++j) if(visited[0][j] < PACIFIC)
            dfs(0, j, heights, visited);
        for(int i = 0; i < m; ++i) if(visited[i][n-1] < ATLANTIC)
            dfs(i, n-1, heights, visited, ATLANTIC);
        for(int j = 0; j < n; ++j) if(visited[m-1][j] < ATLANTIC)
            dfs(m-1, j, heights, visited, ATLANTIC);
        vector<vector<int>> ans;
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j)
            if(visited[i][j] == PACIFIC + ATLANTIC)
                ans.push_back({i, j});
        return ans;
    }
};