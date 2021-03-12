class Solution(object):
    def dfs_helper(self, current):
        if not current: return
        if abs(current.val - self.target) < abs(self.closest_value - self.target):
            self.closest_value = current.val
        self.dfs_helper(current.left)
        self.dfs_helper(current.right)
    
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        self.target = target
        self.closest_value = float("inf")
        
        self.dfs_helper(root)
        return self.closest_value