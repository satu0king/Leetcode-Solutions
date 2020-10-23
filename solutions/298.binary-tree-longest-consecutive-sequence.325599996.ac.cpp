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
  int longestConsecutive(TreeNode *root) {
    int ans = 0;
    f(root, ans, NULL);
    return ans;
  }

  void f(TreeNode *root, int &ans, TreeNode *parent, int length = 0) {
    if (!root)
      return;

    length = (parent && parent->val + 1 == root->val) ? length + 1 : 1;
    ans = max(ans, length);

    f(root->left, ans, root, length);
    f(root->right, ans, root, length);
  }
};
