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
  int sumEvenGrandparent(TreeNode *root, bool parent = false,
                         bool gparent = false) {
    if (!root)
      return 0;
    bool even = root->val % 2 == 0;
    return (gparent ? root->val : 0) +
           sumEvenGrandparent(root->left, even, parent) +
           sumEvenGrandparent(root->right, even, parent);
  }
};
