class Solution {
    void transpose(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for(int i = 0; i < n; ++i) for(int j = i+1; j < n; ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
    
    void reverse_rows(vector<vector<int>>& matrix) {
        for(auto& row : matrix)
            reverse(row.begin(), row.end());
    }
    
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse_rows(matrix);
    }
};