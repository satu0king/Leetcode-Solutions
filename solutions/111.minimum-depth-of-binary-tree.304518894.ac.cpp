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
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (l && r)
      return min(l, r) + 1;
    if (l)
      return l + 1;
    return r + 1;
  }
};
