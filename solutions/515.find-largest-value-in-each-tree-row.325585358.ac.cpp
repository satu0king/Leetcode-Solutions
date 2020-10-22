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
  vector<int> largestValues(TreeNode *root) {

    if (!root)
      return {};

    vector<int> ans;
    queue<TreeNode *> q;

    q.push(root);

    while (q.size()) {
      int n = q.size();
      int temp = INT_MIN;
      while (n--) {
        auto node = q.front();
        q.pop();
        temp = max(temp, node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(temp);
    }
    return ans;
  }
};
