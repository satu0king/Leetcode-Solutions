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
  int deepestLeavesSum(TreeNode *root) {
    int ans = 0;
    queue<TreeNode *> q;
    if (!root)
      return 0;
    q.push(root);

    while (q.size()) {
      ans = 0;
      int n = q.size();
      while (n--) {
        auto node = q.front();
        q.pop();
        ans += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }
    return ans;
  }
};
