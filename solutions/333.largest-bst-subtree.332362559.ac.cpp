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
  int largestBSTSubtree(TreeNode *root) {
    int ans = 0;
    f(root, ans);
    return ans;
  }

  tuple<int, int, int> f(TreeNode *root, int &ans) {
    if (!root)
      return {0, 0, 0};

    int c = 1;
    int mn = root->val;
    int mx = root->val;

    auto [lc, lmin, lmax] = f(root->left, ans);
    auto [rc, rmin, rmax] = f(root->right, ans);

    if (root->left) {
      if (!lc || lmax >= root->val)
        return {0, 0, 0};
      mn = lmin;
      c += lc;
    }

    if (root->right) {
      if (!rc || rmin <= root->val)
        return {0, 0, 0};
      mx = rmax;
      c += rc;
    }

    ans = max(ans, c);
    return {c, mn, mx};
  }
};
