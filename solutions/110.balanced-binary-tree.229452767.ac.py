# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        
        flag = True
        
        def f(root):
            nonlocal flag
            if root is None:
                return 0
            
            left = f(root.left)
            right = f(root.right)
            if abs(left-right)>1:
                flag = False
            
            print(root.val, max(left, right) + 1)
            return max(left, right) + 1
        
        f(root)
        
        return flag
        
