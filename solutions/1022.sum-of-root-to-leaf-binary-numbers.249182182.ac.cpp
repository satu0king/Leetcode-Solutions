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
  int sumRootToLeaf(TreeNode *root, int c = 0) {
    if (!root)
      return c;

    c *= 2;
    c += root->val;
    if (!root->left && !root->right)
      return c;

    int ans = 0;

    if (root->left)
      ans += sumRootToLeaf(root->left, c);
    if (root->right)
      ans += sumRootToLeaf(root->right, c);
    return ans;
  }
};
