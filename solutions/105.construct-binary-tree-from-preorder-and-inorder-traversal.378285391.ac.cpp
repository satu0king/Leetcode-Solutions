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
  unordered_map<int, int> mp;
  TreeNode *f(vector<int> &preorder, int &i, int l, int r) {
    if (l > r)
      return NULL;
    if (i == preorder.size())
      return NULL;
    TreeNode *root = new TreeNode(preorder[i++]);
    int m = mp[root->val];
    root->left = f(preorder, i, l, m - 1);
    root->right = f(preorder, i, m + 1, r);
    return root;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int i = 0;
    for (int i = 0; i < inorder.size(); i++)
      mp[inorder[i]] = i;
    return f(preorder, i, 0, inorder.size() - 1);
  }
};
