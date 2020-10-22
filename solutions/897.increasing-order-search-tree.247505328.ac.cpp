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
  TreeNode *increasingBST(TreeNode *root) {
    if (!root)
      return NULL;

    if (root->left) {
      root->left = increasingBST(root->left);
      root->right = increasingBST(root->right);
      TreeNode *temp = root->left;
      root->left = NULL;
      rightMostChild(temp)->right = root;
      return temp;
    } else {
      root->right = increasingBST(root->right);
      return root;
    }

    return NULL;
  }

  TreeNode *rightMostChild(TreeNode *root) {
    while (root->right)
      root = root->right;

    return root;
  }
};
