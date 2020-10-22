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
  TreeNode *removeLeafNodes(TreeNode *root, int target) {
    TreeNode *dummy = new TreeNode(0);
    dummy->right = root;
    f(root, target, dummy);
    return dummy->right;
  }

  void f(TreeNode *root, int target, TreeNode *parent) {
    if (!root)
      return;
    f(root->left, target, root);
    f(root->right, target, root);

    if (root->val == target && root->left == NULL && root->right == NULL) {
      if (parent->left == root)
        parent->left = NULL;
      if (parent->right == root)
        parent->right = NULL;
    }
  }
};
