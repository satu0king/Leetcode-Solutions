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
  vector<vector<int>> verticalOrder(TreeNode *root) {
    map<int, vector<int>> mp;

    queue<pair<TreeNode *, int>> q;
    q.emplace(root, 0);

    while (q.size()) {
      auto r = q.front();
      q.pop();
      if (!(r.first))
        continue;
      mp[r.second].push_back(r.first->val);
      q.emplace(r.first->left, r.second - 1);
      q.emplace(r.first->right, r.second + 1);
    }
    vector<vector<int>> result;
    for (auto p : mp)
      result.push_back(p.second);
    return result;
  }
};
