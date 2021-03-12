class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        self.left_most(root)
        
    def left_most(self, root):
        while root:
            self.stack.append(root)
            root = root.left

    def next(self) -> int:
        if self.stack:
            current = self.stack[-1]
            self.stack = self.stack[:-1]
            self.left_most(current.right)
            return current.val

    def hasNext(self) -> bool:
        return len(self.stack) > 0