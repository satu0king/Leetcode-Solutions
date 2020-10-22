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
  int maxPathSum(TreeNode *root) {
    int ans = INT_MIN;
    f(root, ans);
    return ans;
  }

  int f(TreeNode *root, int &ans) {
    if (!root)
      return 0;

    int left = f(root->left, ans);
    int right = f(root->right, ans);

    ans = max(ans, root->val + left + right);

    return max(0, root->val + max(left, right));
  }
};
