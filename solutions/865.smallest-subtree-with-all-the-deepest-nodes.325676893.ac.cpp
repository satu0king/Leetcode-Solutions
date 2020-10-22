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
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    if (!root)
      return root;
    int height = h(root);
    return f(root, 1, height);
  }

  TreeNode *f(TreeNode *root, int depth, int height) {
    if (!root)
      return NULL;

    if (depth == height)
      return root;

    auto l = f(root->left, depth + 1, height);
    auto r = f(root->right, depth + 1, height);

    if (l && r)
      return root;
    if (l)
      return l;
    if (r)
      return r;
    return NULL;
  }

  int h(TreeNode *root) {
    if (!root)
      return 0;
    return 1 + max(h(root->left), h(root->right));
  }
};
