# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def insertIntoMaxTree(self, root, val):
        if root is None or val> root.val:
            n = TreeNode(val)
            n.left = root
            return n
        else:
            root.right = self.insertIntoMaxTree(root.right, val)
            return root
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        
