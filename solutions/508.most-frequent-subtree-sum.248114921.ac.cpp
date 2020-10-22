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
  unordered_map<int, int> count;
  int mx;

public:
  vector<int> findFrequentTreeSum(TreeNode *root) {

    vector<int> ans;
    if (!root)
      return {};
    mx = 0;
    f(root);

    for (auto p : count)
      if (p.second == mx)
        ans.push_back(p.first);

    return ans;
  }

  int f(TreeNode *root) {
    if (!root)
      return NULL;

    int sum = root->val + f(root->left) + f(root->right);
    count[sum]++;
    mx = max(mx, count[sum]);
    return sum;
  }
};
