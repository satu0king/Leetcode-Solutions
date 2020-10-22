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
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    vector<TreeNode *> ans;
    unordered_set<int> set;
    set.insert(to_delete.begin(), to_delete.end());
    TreeNode *temp = del(root, set, ans);
    if (temp)
      ans.push_back(temp);
    return ans;
  }

  TreeNode *del(TreeNode *root, unordered_set<int> &to_delete,
                vector<TreeNode *> &ans) {
    if (!root)
      return NULL;
    if (to_delete.count(root->val)) {
      TreeNode *temp = del(root->left, to_delete, ans);
      if (temp)
        ans.push_back(temp);
      temp = del(root->right, to_delete, ans);
      if (temp)
        ans.push_back(temp);
      return NULL;
    } else {
      root->left = del(root->left, to_delete, ans);
      root->right = del(root->right, to_delete, ans);
    }
    return root;
  }
};
