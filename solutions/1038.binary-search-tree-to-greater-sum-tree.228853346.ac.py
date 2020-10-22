# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        
        def f(root, val = 0):
        
            if root is None:
                return 0

            rightValue = f(root.right, val)
            leftValue = f(root.left, root.val + rightValue + val)

            t = root.val
            root.val += rightValue + val
            
            return t + leftValue + rightValue
        
        f(root)
        return root
        
        
        
