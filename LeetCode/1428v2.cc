/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
    int find_left_most(BinaryMatrix& binaryMatrix, int row, int cols) {
        int left_most{-1};
        for(int b = cols; b >= 1; b /= 2)
            while(left_most + b < cols && binaryMatrix.get(row, left_most+b) == 0) left_most += b;
        return left_most + 1;
    }
    
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int rows{dimensions[0]}, cols{dimensions[1]};
        int left_most{cols};
        for(int i = 0; i < rows; ++i) {
            if(left_most == 0 || left_most < cols && binaryMatrix.get(i, left_most-1) == 0) continue;
            left_most = min(left_most, find_left_most(binaryMatrix, i, cols));
        }
        return left_most == cols ? -1 : left_most;
    }
};