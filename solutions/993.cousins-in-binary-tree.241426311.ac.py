class Solution(object):
    def isCousins(self, root, x, y):
        parent = {}
        depth = {}
        def dfs(node, par = None):
            if node:
                depth[node.val] = 1 + depth[par.val] if par else 0
                parent[node.val] = par
                dfs(node.left, node)
                dfs(node.right, node)

        dfs(root)
        return depth[x] == depth[y] and parent[x] != parent[y]
