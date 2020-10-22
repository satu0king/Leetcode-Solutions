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

  unordered_map<int, int> mp;

public:
  TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
    int n = post.size();
    for (int i = 0; i < n; i++)
      mp[post[i]] = i;
    int i = 0;
    return f(pre, post, i, n);
  }

  TreeNode *f(vector<int> &pre, vector<int> &post, int &i, int rightIdx) {
    int n = post.size();
    if (i == n)
      return NULL;
    int val = pre[i];
    int idx = mp[val];
    if (idx >= rightIdx)
      return NULL;
    i++;

    TreeNode *t = new TreeNode(val);
    t->left = f(pre, post, i, idx - 1);
    t->right = f(pre, post, i, rightIdx);
    return t;
  }
};
