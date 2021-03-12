class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        diameter = 0
        def DFS(current):
            nonlocal diameter
            if not current: return 0
            left = DFS(current.left)
            right = DFS(current.right)
            diameter = max(diameter, left + right + 1)
            return max(left, right) + 1
        
        DFS(root)
        return diameter - 1