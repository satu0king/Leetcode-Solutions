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
  vector<int> findMode(TreeNode *root) {
    vector<int> ans;
    int maxCount = 0;
    int count = 0;
    TreeNode *prev = NULL;
    f(root, ans, maxCount, count, prev);
    return ans;
  }

  void f(TreeNode *root, vector<int> &ans, int &maxCount, int &count,
         TreeNode *&prev) {
    if (!root)
      return;
    f(root->left, ans, maxCount, count, prev);

    if (prev && prev->val == root->val) {
      count++;
    } else {
      count = 1;
      prev = root;
    }

    if (count > maxCount) {
      ans.clear();
      ans.push_back(root->val);
      maxCount = count;
    } else if (count == maxCount) {
      ans.push_back(root->val);
    }

    f(root->right, ans, maxCount, count, prev);
  }
};
