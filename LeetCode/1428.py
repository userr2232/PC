class Solution:
    def check_col(self, col):
        for x in col:
            if x == 1: return True
        return False
    
    def find_min_col(self):
        mn, mx = 0, self.n_cols - 1
        col = None
        idx = (mn + mx) // 2
        col = self.get_col(idx)
        while mn < mx:
            if self.check_col(col):
                mx = idx
            else:
                mn = idx + 1
            idx = (mn + mx) // 2
            col = self.get_col(idx)
        if self.check_col(col): return idx
        else: return -1
        
    def get_col(self, idx):
        return [ self.bin.get(i, idx) for i in range(self.n_rows) ]      
    
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        self.bin = binaryMatrix
        self.n_rows, self.n_cols = binaryMatrix.dimensions()
        return self.find_min_col()