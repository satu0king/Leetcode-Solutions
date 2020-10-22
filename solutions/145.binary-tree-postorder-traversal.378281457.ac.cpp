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
  vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> res;
    while (root || s.size()) {
      while (root) {
        s.push(root);
        root = root->left;
      }
      root = s.top();
      if (root->right) {
        root = root->right;
      } else {
        s.pop();
        res.push_back(root->val);
        while (s.size() && s.top()->right == root) {
          root = s.top();
          s.pop();
          res.push_back(root->val);
        }
        root = NULL;
      }
    }
    return res;
  }
};
