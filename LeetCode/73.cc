class Solution {  
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool column0 = false;
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) if(matrix[i][j] == 0) {
            matrix[i][0] = 0;
            if(j == 0) column0 = true;
            else matrix[0][j] = 0;
        }
        for (int i = m-1; i >= 0; --i) { 
            for (int j = 1; j < n; ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
          if(column0) matrix[i][0] = 0;
        }
    }
};