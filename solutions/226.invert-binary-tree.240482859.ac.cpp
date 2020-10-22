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
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return root;

    TreeNode *temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
  }
};
