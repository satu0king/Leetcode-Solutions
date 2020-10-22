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
  int goodNodes(TreeNode *root, int mx = INT_MIN) {
    if (!root)
      return 0;
    mx = max(mx, root->val);
    int s = goodNodes(root->left, mx) + goodNodes(root->right, mx);
    if (root->val == mx)
      s++;
    return s;
  }
};
