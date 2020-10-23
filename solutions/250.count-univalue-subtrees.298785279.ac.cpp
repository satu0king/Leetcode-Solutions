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
  int countUnivalSubtrees(TreeNode *root) {
    int ans = 0;
    f(root, ans);
    return ans;
  }

  bool f(TreeNode *root, int &ans) {
    if (!root)
      return true;

    bool left = f(root->left, ans);
    bool right = f(root->right, ans);

    if (left && right && (!root->left || root->left->val == root->val) &&
        (!root->right || root->right->val == root->val)) {
      ans++;
      return true;
    }
    return false;
  }
};
