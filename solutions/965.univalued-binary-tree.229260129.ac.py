# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root: TreeNode, val = None) -> bool:
        
        if root is None:
            return True
        
        if val is None or root.val == val:
            return self.isUnivalTree(root.left, root.val) and self.isUnivalTree(root.right, root.val)
            
        
        
        return False
        
        
