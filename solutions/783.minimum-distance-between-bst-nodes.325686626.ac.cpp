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
  int minDiffInBST(TreeNode *root) {
    int ans = INT_MAX;
    TreeNode *prev = NULL;
    f(root, prev, ans);
    return ans;
  }
  void f(TreeNode *root, TreeNode *&prev, int &ans) {
    if (!root)
      return;

    f(root->left, prev, ans);
    if (prev)
      ans = min(ans, root->val - prev->val);
    prev = root;
    f(root->right, prev, ans);
  }
};
