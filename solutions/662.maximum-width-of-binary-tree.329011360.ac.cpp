/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {
    int ans = 0;
    queue<pair<TreeNode *, int>> q;
    if (!root)
      return 0;
    q.emplace(root, 0);

    while (q.size()) {
      int n = q.size();

      int mi = INT_MAX;
      int mx = INT_MIN;
      auto [_, startIdx] = q.front();
      while (n--) {
        auto [node, idx] = q.front();
        q.pop();

        mi = min(mi, idx);
        mx = max(mx, idx);
        if (node->left)
          q.emplace(node->left, 2 * (idx - startIdx) + 1);
        if (node->right)
          q.emplace(node->right, 2 * (idx - startIdx) + 2);
      }

      ans = max(ans, mx - mi + 1);
    }
    return ans;
  }
};
