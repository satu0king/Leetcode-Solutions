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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;

    queue<TreeNode *> q;
    if (!root)
      return result;

    q.push(root);

    while (q.size()) {
      int n = q.size();
      int lastSeen = -1;
      while (n--) {
        auto node = q.front();
        q.pop();
        lastSeen = node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      result.push_back(lastSeen);
    }

    return result;
  }
};
