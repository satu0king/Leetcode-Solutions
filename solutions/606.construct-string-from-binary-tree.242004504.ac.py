# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        if t is None:
            return ""
        
        l = self.tree2str(t.left)
        r = self.tree2str(t.right)
        
        if l or r:
            l = "(" + l + ")"
            if r:
                r = "(" + r + ")"
        
        return str(t.val) + l + r
