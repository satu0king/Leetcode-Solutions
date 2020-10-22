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

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
      mp[inorder[i]] = i;
    std::function<TreeNode *(int, int)> f;
    int i = postorder.size() - 1;
    f = [&](int l, int r) -> TreeNode * {
      if (l > r || i == -1)
        return NULL;
      TreeNode *root = new TreeNode(postorder[i--]);
      int m = mp[root->val];
      root->right = f(m + 1, r);
      root->left = f(l, m - 1);
      return root;
    };
    return f(0, i);
  }
};
