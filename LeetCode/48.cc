class Solution {
    void rotate(const int& start, const int& end, vector<vector<int>>& matrix) {
        const int diff = end-start;
        for(int m = 0; m < diff; m++) {
            int i{start}, j{start+m};
            int di{0}, dj{-1};
            for(int k = 0; k < 3; ++k) {
                int next_di{-dj}, next_dj{di};
                int next_i{i+di*diff}, next_j{j+dj*diff};
                int excess_i{next_i < start ? next_i-start : next_i > end ? next_i-end : 0};
                int excess_j{next_j < start ? next_j-start : next_j > end ? next_j-end : 0};
                next_i -= excess_i, next_j -= excess_j;
                next_i += next_di * abs(excess_j), next_j += next_dj * abs(excess_i);
                swap(matrix[i][j], matrix[next_i][next_j]);
                di = next_di, dj = next_dj;
                i = next_i, j = next_j;
            }
        }
    }
    
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        int l{0}, r{n-1};
        while(l < r) {
            rotate(l, r, matrix);
            l++, r--;
        }
    }
};