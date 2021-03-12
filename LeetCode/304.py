class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        n, m = 0, 0
        n = len(matrix)
        if n:
            m = len(matrix[0])
        if not n or not m: return
        self.dp = [ [0] * (m + 1) for i in range(n + 1) ]
        for r in range(n):
            for c in range(m):
                self.dp[r+1][c+1] = self.dp[r+1][c] + self.dp[r][c+1] - self.dp[r][c] + matrix[r][c]
    
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.dp[row2+1][col2+1] - self.dp[row1][col2+1] - self.dp[row2+1][col1]  + self.dp[row1][col1]