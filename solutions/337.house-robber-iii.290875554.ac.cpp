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
  int rob(TreeNode *root) {
    auto p = f(root);
    return max(p.first, p.second);
  }

  pair<int, int> f(TreeNode *root) {
    if (!root)
      return make_pair(0, 0);
    pair<int, int> ans;
    ans.first = root->val;
    auto p1 = f(root->left);
    auto p2 = f(root->right);
    ans.first += p1.second + p2.second;
    ans.second = p1.first + p2.first;
    ans.first = max(ans.first, ans.second);
    return ans;
  }
};
