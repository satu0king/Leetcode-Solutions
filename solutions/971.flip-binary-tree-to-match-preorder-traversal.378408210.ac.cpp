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
  vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
    vector<int> ans;
    int i = 0;
    if (!f(root, voyage, i, ans) || i != voyage.size())
      return {-1};
    return ans;
  }
  bool f(TreeNode *root, vector<int> &voyage, int &i, vector<int> &ans) {
    if (!root)
      return true;
    if (root->val != voyage[i])
      return false;
    i++;
    if (root->left && root->right) {
      if (root->left->val == voyage[i]) {
        return f(root->left, voyage, i, ans) && f(root->right, voyage, i, ans);
      } else if (root->right->val == voyage[i]) {
        ans.push_back(root->val);
        return f(root->right, voyage, i, ans) && f(root->left, voyage, i, ans);
      }
    } else if (root->left)
      return f(root->left, voyage, i, ans);
    else if (root->right)
      return f(root->right, voyage, i, ans);
    return true;
  }
};
