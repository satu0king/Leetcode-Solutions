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
  int closestValue(TreeNode *root, double target) {
    int ans = root->val;
    f(root, target, ans);
    return ans;
  }

  void f(TreeNode *root, double target, int &ans) {
    if (!root)
      return;

    if (abs(target - root->val) < abs(target - ans))
      ans = root->val;

    f(root->left, target, ans);
    f(root->right, target, ans);
  }
};
