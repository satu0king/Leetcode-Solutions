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
  vector<int> v;
  TreeNode *recur(int l, int r) {
    if (l > r)
      return NULL;
    int idx = 0, maxi = -1;
    for (int i = l; i <= r; i++) {
      if (v[i] > maxi) {
        idx = i, maxi = v[i];
      }
    }
    TreeNode *root = new TreeNode(maxi);
    root->left = recur(l, idx - 1);
    root->right = recur(idx + 1, r);
    return root;
  }
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    struct TreeNode *root;
    int n = nums.size();
    v = nums;
    if (nums.size() == 0)
      return NULL;
    // struct TreeNode* head = root;
    return recur(0, n - 1);
    // return head;
  }
};
