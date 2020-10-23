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
  vector<TreeNode *> splitBST(TreeNode *root, int V) {
    if (!root)
      return {NULL, NULL};
    auto leftSplit = splitBST(root->left, V);
    auto rightSplit = splitBST(root->right, V);

    TreeNode *smaller = NULL;
    TreeNode *bigger = NULL;

    if (root->val <= V) {
      smaller = root;
      smaller->right = rightSplit[0];
      bigger = rightSplit[1];
    } else {
      bigger = root;
      bigger->left = leftSplit[1];
      smaller = leftSplit[0];
    }
    return {smaller, bigger};
  }
};
