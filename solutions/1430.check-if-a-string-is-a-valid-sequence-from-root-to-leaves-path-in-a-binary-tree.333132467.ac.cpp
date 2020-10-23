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
  bool isValidSequence(TreeNode *root, vector<int> &arr, int i = 0) {
    if (!root || root->val != arr[i])
      return false;
    if (i == arr.size() - 1)
      return !root->left && !root->right;

    return isValidSequence(root->left, arr, i + 1) ||
           isValidSequence(root->right, arr, i + 1);
  }
};
