class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        root = p
        while root.parent:
            root = root.parent
        def dfs_helper(cur, p, q):
            if not cur: return None
            if cur == p or cur == q: return cur
            left = dfs_helper(cur.left, p, q)
            right = dfs_helper(cur.right, p, q)
            if left and right: return cur
            if not left and not right: return None
            return left if left else right
            
        return dfs_helper(root, p, q)