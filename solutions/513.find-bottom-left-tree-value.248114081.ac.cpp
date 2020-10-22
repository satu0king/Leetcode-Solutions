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
  int findBottomLeftValue(TreeNode *root) {
    if (!root)
      return -1;

    queue<TreeNode *> q;
    q.push(root);

    TreeNode *ans = NULL;

    while (q.size()) {
      int n = q.size();
      ans = q.front();
      while (n--) {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }
    }

    return ans->val;
  }
};
