/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>

class Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    queue<TreeNode *> queue;

    queue.push(root);

    bool lastLevel = false;

    while (queue.size()) {

      TreeNode *root = queue.front();
      queue.pop();

      if (root->left && lastLevel)
        return false;

      else if (!root->left)
        lastLevel = true;

      if (root->right && lastLevel)
        return false;
      else if (!root->right)
        lastLevel = true;

      if (root->left)
        queue.push(root->left);
      if (root->right)
        queue.push(root->right);
    }

    return true;
  }
};
