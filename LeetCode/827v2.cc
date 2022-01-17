class Solution {
    const int UNDEFINED = -1;
    vector<vector<int>> components;
    map<int,int> component_size;
    
    bool valid(int i, int j, const int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
    
    void dfs(const vector<vector<int>>& grid, int i, int j, int component_id) {
        components[i][j] = component_id;
        ++component_size[component_id];
        const int n = grid.size();
        for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) 
            if(abs(di) != abs(dj) && valid(i+di, j+dj, n)) {
                int new_i{i+di}, new_j{j+dj};
                if(grid[new_i][new_j] == 1 && components[new_i][new_j] == UNDEFINED) 
                    dfs(grid, new_i, new_j, component_id);
            }
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        const int n = grid.size();
        components.assign(n, vector<int>(n, UNDEFINED));
        int component_id{0};
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
            if(components[i][j] == UNDEFINED && grid[i][j] == 1) dfs(grid, i, j, component_id++);
        }
        int max_comp_size{0};
        for(const auto& [_, v] : component_size) {
            max_comp_size = max(max_comp_size, v);
        }
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if(grid[i][j] == 0) {
            int size = 1;
            set<int> comps;
            for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) if(abs(di) != abs(dj) && valid(i+di, j+dj, n)) {
                int new_i{i+di}, new_j{j+dj};
                if(grid[new_i][new_j] == 1 && comps.insert(components[new_i][new_j]).second)  {
                    size += component_size[components[new_i][new_j]];
                }
            }
            max_comp_size = max(max_comp_size, size);
            
        }
        return max_comp_size;
    }
};