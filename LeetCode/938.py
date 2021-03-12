class Solution:
    def dfs(self, current):
        if not current: return
        if current not in self.visited and self.low <= current.val <= self.high:
            self.s += current.val
        self.visited.add(current)
        self.dfs(current.left)
        self.dfs(current.right)
        
            
    
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        self.low, self.high = low, high
        self.root = root
        self.visited = set()
        self.s = 0
        self.dfs(self.root)
        return self.s