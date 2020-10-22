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
  vector<TreeNode *> generateTrees(int n) {
    vector<vector<vector<TreeNode *>>> dp(n + 2,
                                          vector<vector<TreeNode *>>(n + 2));

    for (int d = 0; d < n; d++)
      for (int i = 1; i <= n - d; i++)
        for (int k = i; k <= i + d; k++) {

          auto &left = dp[i][k - 1];
          auto &right = dp[k + 1][i + d];
          if (left.empty())
            left.push_back(NULL);
          if (right.empty())
            right.push_back(NULL);

          for (auto l : left)
            for (auto r : right) {
              auto node = new TreeNode(k);
              node->left = l;
              node->right = r;
              dp[i][i + d].push_back(node);
            }
        }
    return dp[1][n];
  }
};
