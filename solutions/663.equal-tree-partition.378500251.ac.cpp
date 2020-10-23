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
  bool checkEqualTree(TreeNode *root) {
    int s = sum(root);
    bool ans = false;
    f(root, ans, s);
    return ans;
  }
  int f(TreeNode *root, bool &ans, int s, TreeNode *parent = NULL) {
    if (!root)
      return 0;
    int l = f(root->left, ans, s, root);
    int r = f(root->right, ans, s, root);
    int v = root->val;
    if (2 * (l + v + r) == s && parent) {
      ans = true;
    }
    return l + r + v;
  }

  int sum(TreeNode *root) {
    if (!root)
      return 0;
    return root->val + sum(root->left) + sum(root->right);
  }
};
