class Solution:
    def connect(self, left, right):
        if left and right:
            left.right = right
            right.left = left
            
    def DFS(self, current):
        if not current: return None, None
        mn, predecesor = self.DFS(current.left)
        successor, mx = self.DFS(current.right)
        self.connect(predecesor, current)
        self.connect(current, successor)
        return mn if mn else current, mx if mx else current
    
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        first, last = self.DFS(root)
        self.connect(last, first)
        return first