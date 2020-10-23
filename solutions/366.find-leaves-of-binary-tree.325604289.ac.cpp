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
  vector<vector<int>> findLeaves(TreeNode *root) {
    vector<vector<int>> ans;
    dfs(root, ans);
    return ans;
  }

  int dfs(TreeNode *root, vector<vector<int>> &ans) {
    if (!root)
      return 0;
    int level = max(dfs(root->left, ans), dfs(root->right, ans));
    if (level == ans.size())
      ans.push_back({});
    ans[level].push_back(root->val);
    return level + 1;
  }
};
