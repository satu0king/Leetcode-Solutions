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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    if (!root)
      return ans;
    queue<TreeNode *> q;
    q.push(root);

    while (int n = q.size()) {
      double temp = 0;
      for (int i = 0; i < n; i++) {
        auto node = q.front();
        q.pop();
        temp += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(temp / n);
    }
    return ans;
  }
};
