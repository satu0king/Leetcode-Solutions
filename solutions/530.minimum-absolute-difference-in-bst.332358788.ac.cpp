/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int getMinimumDifference(TreeNode *root) {
    int ans = INT_MAX;
    TreeNode *prev = NULL;
    f(root, ans, prev);
    return ans;
  }

  void f(TreeNode *root, int &ans, TreeNode *&prev) {
    if (!root)
      return;

    f(root->left, ans, prev);

    if (prev)
      ans = min(ans, root->val - prev->val);

    prev = root;

    f(root->right, ans, prev);
  }
};
