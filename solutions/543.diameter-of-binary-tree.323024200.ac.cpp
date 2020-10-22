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
  int diameterOfBinaryTree(TreeNode *root) {
    int ans = 0;
    f(root, ans);
    return ans;
  }

  int f(TreeNode *root, int &ans) {
    if (!root)
      return 0;

    int l = f(root->left, ans);
    int r = f(root->right, ans);

    ans = max(ans, l + r);

    return 1 + max(l, r);
  }
};
