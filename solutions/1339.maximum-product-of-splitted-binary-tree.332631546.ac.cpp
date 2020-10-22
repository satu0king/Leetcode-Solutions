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
  int maxProduct(TreeNode *root) {
    vector<int> sums;
    int t = dfs(root, sums);
    long ans = 0;
    for (int s : sums)
      ans = max(ans, (long)(t - s) * s);
    const int p = 1e9 + 7;
    return ans % p;
  }

  int dfs(TreeNode *root, vector<int> &sums) {
    if (!root)
      return 0;
    int s = dfs(root->left, sums) + dfs(root->right, sums) + root->val;
    sums.push_back(s);
    return s;
  }
};
