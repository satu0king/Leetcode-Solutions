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

  map<tuple<int, int, int>, int> mp;
  unordered_map<int, int> keyCount;

public:
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    vector<TreeNode *> ans;
    f(root, ans);

    return ans;
  }

  int getId(tuple<int, int, int> key) {
    if (mp.count(key))
      return mp[key];
    return mp[key] = mp.size();
  }

  int f(TreeNode *root, vector<TreeNode *> &ans) {
    if (!root)
      return -1;

    int leftId = f(root->left, ans);
    int rightId = f(root->right, ans);
    int id = getId({root->val, leftId, rightId});
    if (keyCount[id]++ == 1)
      ans.push_back(root);

    return id;
  }
};
