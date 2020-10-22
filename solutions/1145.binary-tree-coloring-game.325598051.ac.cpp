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
  bool btreeGameWinningMove(TreeNode *root, int n, int x) {
    if (!root)
      return false;
    if (root->val == x) {
      int l = count(root->left);
      int r = count(root->right);
      int u = n - l - r - 1;
      int x = max(max(l, r), u);
      return x > n - x;
    } else
      return btreeGameWinningMove(root->left, n, x) ||
             btreeGameWinningMove(root->right, n, x);
  }

  int count(TreeNode *root) {
    return root ? count(root->left) + count(root->right) + 1 : 0;
  }
};
