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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return _sortedArrayToBST(nums, 0, nums.size() - 1);
  }

  TreeNode *_sortedArrayToBST(vector<int> &nums, int l, int r) {

    if (l > r) {
      return NULL;
    }
    if (l == r) {
      return new TreeNode(nums[l]);
    }

    int mid = (r + l) / 2;

    TreeNode *temp = new TreeNode(nums[mid]);
    temp->left = _sortedArrayToBST(nums, l, mid - 1);
    temp->right = _sortedArrayToBST(nums, mid + 1, r);
    return temp;
  }
};
