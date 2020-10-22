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
  int findSecondMinimumValue(TreeNode *root) {
    if (!root)
      return -1;
    int v1 = -1;
    int v2 = -1;
    findMin(root, v1, v2);
    return v2;
  }

  void findMin(TreeNode *root, int &v1, int &v2) {
    if (!root)
      return;

    if (root->val == v1)
      ;
    else if (root->val < v1 || v1 == -1) {
      v2 = v1;
      v1 = root->val;
    } else if (root->val < v2 || v2 == -1) {
      v2 = root->val;
    }
    findMin(root->left, v1, v2);
    findMin(root->right, v1, v2);
  }
};
