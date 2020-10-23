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
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    if (p->right != NULL) {
      TreeNode *curr = p->right;
      while (curr->left != NULL) {
        curr = curr->left;
      }
      return curr;
    } else {
      TreeNode *ans = NULL;
      int val = 1e9 + 7;
      TreeNode *curr = root;
      while (curr != p) {
        if (curr->val > p->val) {
          if (val > curr->val) {
            val = curr->val;
            ans = curr;
          }
        }
        if (p->val > curr->val) {
          curr = curr->right;
        } else {
          curr = curr->left;
        }
      }
      return ans;
    }
  }
};
