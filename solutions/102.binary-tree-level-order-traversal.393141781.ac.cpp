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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == NULL)
      return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (q.size()) {
      int t = q.size();
      vector<int> currentLevel;
      while (t--) {
        TreeNode *temp = q.front();
        q.pop();
        currentLevel.push_back(temp->val);
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }
      ans.push_back(currentLevel);
    }
    return ans;
  }
};
