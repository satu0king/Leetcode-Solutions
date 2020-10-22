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
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    int i = 0;
    return f(preorder, i);
  }
  TreeNode *f(vector<int> &preorder, int &i, TreeNode *low = NULL,
              TreeNode *high = NULL) {
    if (i == preorder.size())
      return NULL;

    if (low && preorder[i] < low->val)
      return NULL;
    if (high && preorder[i] > high->val)
      return NULL;

    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = f(preorder, i, low, root);
    root->right = f(preorder, i, root, high);

    return root;
  }
};
