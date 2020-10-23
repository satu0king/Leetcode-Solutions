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
  vector<int> closestKValues(TreeNode *root, double target, int k) {
    vector<int> larger;
    vector<int> smaller;
    int k1 = k;
    findLarger(root, larger, target, k1);
    k1 = k;
    findSmaller(root, smaller, target, k1);
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (k--) {
      if (i == larger.size()) {
        ans.push_back(smaller[j++]);
      } else if (j == smaller.size()) {
        ans.push_back(larger[i++]);
      } else if (larger[i] - target < target - smaller[j]) {
        ans.push_back(larger[i++]);
      } else {
        ans.push_back(smaller[j++]);
      }
    }
    return ans;
  }

  TreeNode *findLarger(TreeNode *root, vector<int> &arr, double target, int &k,
                       TreeNode *prev = NULL) {
    if (k <= 0 || !root)
      return prev;
    if (root->val >= target)
      prev = findLarger(root->left, arr, target, k, prev);
    if (arr.size() || (!prev && root->val >= target) ||
        (prev && prev->val <= target && root->val >= target)) {
      arr.push_back(root->val);
      k--;
    }
    prev = findLarger(root->right, arr, target, k, root);
    return prev;
  }

  TreeNode *findSmaller(TreeNode *root, vector<int> &arr, double target, int &k,
                        TreeNode *prev = NULL) {
    if (k <= 0 || !root)
      return prev;
    if (root->val <= target)
      prev = findSmaller(root->right, arr, target, k, prev);
    if (arr.size() || (!prev && root->val < target) ||
        (prev && prev->val >= target && root->val < target)) {
      arr.push_back(root->val);
      k--;
    }
    prev = findSmaller(root->left, arr, target, k, root);
    return prev;
  }
};
