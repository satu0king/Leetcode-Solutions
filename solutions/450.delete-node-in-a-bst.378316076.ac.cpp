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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root)
      return root;
    if (root->val == key) {
      if (root->left && root->right) {
        TreeNode *temp = root->left;
        while (temp->right) {
          temp = temp->right;
        }
        root->val = temp->val;
        root->left = deleteNode(root->left, root->val);
      } else if (root->left)
        return root->left;
      else
        return root->right;
    } else if (root->val < key)
      root->right = deleteNode(root->right, key);
    else
      root->left = deleteNode(root->left, key);
    return root;
  }
};
