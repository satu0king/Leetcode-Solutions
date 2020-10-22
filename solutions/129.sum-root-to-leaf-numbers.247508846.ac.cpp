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
  int ans;
  int temp;

public:
  int sumNumbers(TreeNode *root) {
    ans = 0;
    temp = 0;
    if (!root)
      return 0;
    f(root);
    return ans;
  }

  void f(TreeNode *root) {

    temp = temp * 10 + root->val;

    if (root->left)
      f(root->left);
    if (root->right)
      f(root->right);

    if (!root->left && !root->right)
      ans += temp;

    temp /= 10;
  }
};
