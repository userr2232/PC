class Solution {
    int next{0};
    int m, n, unvisited;
    const int INCREMENT{300};
public:
    bool isvalid(complex<double> pos) {
        int row = pos.imag();
        int col = pos.real();
        return row >= 0 && row < m && col >= 0 && col < n;
    }
    
    bool isunvisited(vector<vector<int>>& matrix, complex<double> pos) {
        int row = pos.imag();
        int col = pos.real();
        return matrix[row][col] <= 100;
    }
    
    void visit(vector<vector<int>>& matrix, complex<double> pos, vector<int>& ans) {
        int row = pos.imag();
        int col = pos.real();
        ans[next++] = matrix[row][col];
        matrix[row][col] += INCREMENT;
        unvisited--;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size(),
        n = matrix[0].size(); 
        unvisited = m*n;
        vector<int> ans(m*n);
        complex<double> pos{0,0}, dir{1,0};
        while(unvisited) {
            if(isvalid(pos) && isunvisited(matrix, pos)) visit(matrix, pos, ans), pos += dir;
            else pos -= dir, dir={dir.imag(), -dir.real()}, pos += dir;
        }
        return ans;
    }
};