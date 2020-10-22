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
  int sumOfLeftLeaves(TreeNode *root, bool left = false) {
    if (!root)
      return 0;
    if (left && !root->left && !root->right)
      return root->val;
    return sumOfLeftLeaves(root->left, true) +
           sumOfLeftLeaves(root->right, false);
  }
};
