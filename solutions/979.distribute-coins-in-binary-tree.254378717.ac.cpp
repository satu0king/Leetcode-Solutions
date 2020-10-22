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

public:
  int distributeCoins(TreeNode *root) {
    ans = 0;
    f(root);
    return ans;
  }

  int f(TreeNode *root) {
    if (!root)
      return 0;

    root->val += f(root->left) + f(root->right) - 1;

    ans += abs(root->val);
    return root->val;
  }
};
