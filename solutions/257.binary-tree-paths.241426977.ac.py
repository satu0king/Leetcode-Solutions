# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        ans = []
        
        if root is None:
            return ans
        
        
        def f(node, path = ""):
            
            if node is None:
                return 
            
            if path:
                path+="->" + str(node.val)
            else:
                path = str(node.val)
                
            if node.left is None and node.right is None:
                ans.append(path)
                return
            
            f(node.left, path)
            f(node.right, path)
            
        f(root)
        
        
        
        return ans; 
