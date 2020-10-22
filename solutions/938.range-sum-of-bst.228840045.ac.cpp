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
  int rangeSumBST(TreeNode *root, int L, int R) {

    int t = root->val;

    if (root->val < L || root->val > R)
      t = 0;

    if (root->left && root->val > L)
      t += rangeSumBST(root->left, L, R);
    if (root->right && root->val < R)
      t += rangeSumBST(root->right, L, R);
    return t;
  }
};
