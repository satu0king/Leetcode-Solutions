/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int findClosestLeaf(TreeNode *root, int k) {
    unordered_map<TreeNode *, vector<TreeNode *>> graph;
    TreeNode *start = NULL;

    // Build graph, and look for the starting node (i.e. root->val == k) at the
    // same time
    function<void(TreeNode *, TreeNode *)> buildGraph = [&](TreeNode *root,
                                                            TreeNode *parent) {
      if (!root)
        return;
      if (root->val == k)
        start = root;
      if (parent) {
        graph[parent].push_back(root);
        graph[root].push_back(parent);
      }
      buildGraph(root->left, root);
      buildGraph(root->right, root);
    };
    buildGraph(root, NULL);

    // Start BFS
    unordered_set<TreeNode *> seen;
    queue<TreeNode *> q;
    q.push(start);
    while (!q.empty()) {
      TreeNode *current = q.front();
      q.pop();
      if (!current->left && !current->right)
        return current->val; // First leaf node we find, return it
      seen.insert(current);
      for (auto &nei : graph[current]) {
        if (seen.find(nei) != seen.end())
          continue;
        q.push(nei);
      }
    }

    return -1; // dummy value!!!
  }
};
