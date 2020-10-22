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
  bool isSubtree(TreeNode *s, TreeNode *t) {
    if (!s && !t)
      return true;
    if (!s || !t)
      return false;

    return f(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
  }

  bool f(TreeNode *s, TreeNode *t) {
    if (!s && !t)
      return true;
    if (!s || !t)
      return false;

    return s->val == t->val && f(s->right, t->right) && f(s->left, t->left);
  }
};
