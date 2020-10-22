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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    queue<TreeNode *> q;

    vector<vector<int>> ans;

    if (!root)
      return ans;

    q.push(root);

    while (!q.empty()) {
      vector<int> temp;
      int n = q.size();
      for (int i = 0; i < n; i++) {
        TreeNode *r = q.front();
        q.pop();
        temp.push_back(r->val);
        if (r->left)
          q.push(r->left);
        if (r->right)
          q.push(r->right);
      }
      ans.push_back(temp);
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
