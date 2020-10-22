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
  int longestZigZag(TreeNode *root) {

    int ans = 0;
    d(root, ans);
    return ans;
  }

  int d(TreeNode *root, int &ans, int dir = -1) {
    if (!root)
      return 0;

    int r = d(root->right, ans, 1);
    int l = d(root->left, ans, 0);

    ans = max(r, ans);
    ans = max(l, ans);

    if (!dir)
      return r + 1;
    return l + 1;
  }
};
