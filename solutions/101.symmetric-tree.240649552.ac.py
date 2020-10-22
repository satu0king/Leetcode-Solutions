# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        
        
        def f(left, right):
            
            if left is None and right is None:
                return True
            
            if left is None or right is None:
                return False
            
            if left.val!= right.val:
                return False
            
            return f(left.right, right.left) and f(left.left, right.right)
        
        if root is None:
            return True
        
        return f(root.left, root.right)
            
