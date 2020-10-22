# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        
        def f(node):
            if node is None:
                return []
            
            if node.left is None and node.right is None:
                return [node.val]
            
            return f(node.left) + f(node.right)
        
        return f(root1)  == f(root2)
        
