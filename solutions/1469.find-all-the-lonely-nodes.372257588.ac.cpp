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
  vector<int> getLonelyNodes(TreeNode *root) {
    vector<int> ans;
    f(root, ans);
    return ans;
  }

  void f(TreeNode *root, vector<int> &ans) {
    if (!root)
      return;
    if (root->left && !root->right)
      ans.push_back(root->left->val);
    if (!root->left && root->right)
      ans.push_back(root->right->val);
    f(root->left, ans);
    f(root->right, ans);
  }
};
