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
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> ans;
    vector<int> path;
    addPath(root, sum, path, ans);
    return ans;
  }

  void addPath(TreeNode *root, int sum, vector<int> &path,
               vector<vector<int>> &ans) {
    if (!root)
      return;

    sum -= root->val;
    path.push_back(root->val);

    if (!root->left && !root->right)
      if (sum == 0)
        ans.push_back(path);

    addPath(root->left, sum, path, ans);
    addPath(root->right, sum, path, ans);

    path.pop_back();
  }
};
