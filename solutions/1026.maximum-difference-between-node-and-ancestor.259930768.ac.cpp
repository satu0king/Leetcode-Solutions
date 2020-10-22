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
  int ans = 0;

public:
  int maxAncestorDiff(TreeNode *root) {
    if (!root)
      return 0;
    f(root, root->val, root->val);
    return ans;
  }

  void f(TreeNode *root, int mx, int mn) {
    if (!root)
      return;
    int v = root->val;
    ans = max(ans, abs(v - mx));
    ans = max(ans, abs(v - mn));
    mx = max(mx, v);
    mn = min(mn, v);
    f(root->left, mx, mn);
    f(root->right, mx, mn);
  }
};
