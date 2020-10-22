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
  int ans;

public:
  int longestUnivaluePath(TreeNode *root) {
    ans = 0;
    f(root);
    return ans;
  }

  int f(TreeNode *root) {
    if (!root)
      return 0;

    int leftCount = f(root->left);
    int rightCount = f(root->right);

    int t = 1;
    if (leftCount && root->left->val != root->val)
      leftCount = 0;
    if (rightCount && root->right->val != root->val)
      rightCount = 0;

    ans = max(ans, leftCount + rightCount);
    return max(leftCount, rightCount) + 1;
  }
};
