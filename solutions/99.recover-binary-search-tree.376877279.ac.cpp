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
  void f(TreeNode *root, pair<TreeNode *, TreeNode *> &p, TreeNode *&prev) {
    if (!root)
      return;
    f(root->left, p, prev);
    if (prev && root->val < prev->val) {
      if (p.first == NULL)
        p.first = prev;
      p.second = root;
    }
    prev = root;
    f(root->right, p, prev);
  }

  void recoverTree(TreeNode *root) {
    pair<TreeNode *, TreeNode *> p = {NULL, NULL};
    TreeNode *prev = NULL;
    f(root, p, prev);
    swap(p.first->val, p.second->val);
  }
};
