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
  TreeNode *lcaDeepestLeaves(TreeNode *root) { return countNodes(root).first; }

  pair<TreeNode *, int> countNodes(TreeNode *root) {
    if (!root)
      return {NULL, 0};

    auto p1 = countNodes(root->left);
    auto p2 = countNodes(root->right);
    if (p1.second > p2.second)
      return {p1.first, p1.second + 1};
    if (p1.second < p2.second)
      return {p2.first, p2.second + 1};

    return {root, p2.second + 1};
  }
};
