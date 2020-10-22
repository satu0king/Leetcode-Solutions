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
  int maxLevelSum(TreeNode *root) {
    if (!root)
      return -1;
    int maxSum = root->val;
    int ans = 1;
    queue<TreeNode *> levelOrderQueue;
    levelOrderQueue.push(root);
    int level = 0;
    while (!levelOrderQueue.empty()) {
      int tempSum = 0;
      level++;
      int count = levelOrderQueue.size();
      while (count--) {
        TreeNode *temp = levelOrderQueue.front();
        levelOrderQueue.pop();
        tempSum += temp->val;
        if (temp->left)
          levelOrderQueue.push(temp->left);
        if (temp->right)
          levelOrderQueue.push(temp->right);
      }
      if (tempSum > maxSum) {
        maxSum = tempSum;
        ans = level;
      }
    }

    return ans;
  }
};
