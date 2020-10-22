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
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<int, vector<pair<int, int>>> mp;
    f(mp, root);
    vector<vector<int>> ans;

    for (auto &p : mp) {
      auto &v = p.second;
      sort(v.begin(), v.end());
      ans.push_back({});
      for (auto p : v)
        ans.back().push_back(p.second);
    }

    return ans;
  }

  void f(map<int, vector<pair<int, int>>> &map1, TreeNode *root, int x = 0,
         int y = 0) {
    if (!root)
      return;

    map1[x].emplace_back(-y, root->val);
    f(map1, root->left, x - 1, y - 1);
    f(map1, root->right, x + 1, y - 1);
  }
};
