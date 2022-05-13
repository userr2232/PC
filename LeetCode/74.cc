class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int lo{0}, hi{m*n-1};
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            int row = mid / n, col = mid % n;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) hi = mid-1;
            else lo = mid+1;
        }
        return false;
    }
};