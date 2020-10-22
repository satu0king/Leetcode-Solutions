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
  int pseudoPalindromicPaths(TreeNode *root) {
    unordered_map<int, int> mp;
    if (!root)
      return 0;
    return f(root, mp);
  }

  int f(TreeNode *root, unordered_map<int, int> &mp, int odd = 0) {
    if (!root)
      return 0;
    int v = root->val;
    int c = mp[v];
    mp[v]++;
    if (c % 2 == 0)
      odd++;
    else
      odd--;
    int lscore = f(root->left, mp, odd);
    int rscore = f(root->right, mp, odd);
    mp[v]--;
    if (!root->left && !root->right) {
      return odd <= 1;
    }
    return lscore + rscore;
  }
};
