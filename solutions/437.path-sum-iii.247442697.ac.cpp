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
  int pathSum(TreeNode *root, int sum) {
    unordered_map<int, int> count;
    count[0]++;

    return f(root, sum, count);
  }

  int f(TreeNode *root, int sum, unordered_map<int, int> &count, int prev = 0) {
    int ans = 0;
    if (!root)
      return 0;

    int newSum = prev + root->val;
    ans += count[newSum - sum];

    count[newSum]++;
    ans += f(root->left, sum, count, newSum);
    ans += f(root->right, sum, count, newSum);
    count[newSum]--;

    return ans;
  }
};
