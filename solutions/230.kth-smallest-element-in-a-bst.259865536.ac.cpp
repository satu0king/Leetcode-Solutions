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

  int ans;

public:
  int kthSmallest(TreeNode *root, int k) {
    search(root, k);
    return ans;
  }

  int search(TreeNode *root, int k) {
    if (!root)
      return NULL;

    int leftCount = search(root->left, k);

    if (leftCount + 1 == k)
      ans = root->val;

    int rightCount = search(root->right, k - 1 - leftCount);

    return 1 + leftCount + rightCount;
  }
};
