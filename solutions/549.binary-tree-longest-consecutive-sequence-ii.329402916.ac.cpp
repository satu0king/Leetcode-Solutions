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
  int longestConsecutive(TreeNode *root) {
    int ans = 0;
    f(root, ans);
    return ans;
  }

  pair<int, int> f(TreeNode *root, int &ans) {
    if (!root)
      return {0, 0};

    int inc = 1;
    int dec = 1;

    if (root->left) {
      auto [incL, decL] = f(root->left, ans);
      if (root->left->val == root->val + 1)
        inc = max(inc, incL + 1);
      if (root->left->val == root->val - 1)
        dec = max(dec, decL + 1);
    }

    if (root->right) {
      auto [incR, decR] = f(root->right, ans);
      if (root->right->val == root->val + 1)
        inc = max(inc, incR + 1);
      if (root->right->val == root->val - 1)
        dec = max(dec, decR + 1);
    }

    ans = max(ans, inc + dec - 1);
    return {inc, dec};
  }
};
