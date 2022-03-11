#define INF 2e9

class Solution {
    int m, n;
    
    vector<pair<int,int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool valid(int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int k = m * n;
        int i{0}, j{-1};
        int dir_idx{0};
        vector<int> ans;
        for(int w = 0; w < k; ++w) {
            auto [di, dj] = dirs[dir_idx % 4];
            int i_neighbor{i+di}, j_neighbor{j+dj};
            if(!valid(i+di, j+dj) || matrix[i+di][j+dj] == INF) {
                dir_idx++, w--;
                continue;
            }
            ans.emplace_back(matrix[i_neighbor][j_neighbor]);
            matrix[i_neighbor][j_neighbor] = INF;
            i = i_neighbor, j = j_neighbor;
        }
        return ans;
    }
};