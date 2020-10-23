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
  double maximumAverageSubtree(TreeNode *root) {
    double ans = 0;
    f(root, ans);
    return ans;
  }

  pair<int, int> f(TreeNode *root, double &ans) {
    if (!root)
      return {0, 0};

    auto left = f(root->left, ans);
    auto right = f(root->right, ans);
    int value = left.first + right.first + root->val;
    int c = left.second + right.second + 1;
    ans = max(ans, value / (c + 0.0));
    return {value, c};
  }
};
