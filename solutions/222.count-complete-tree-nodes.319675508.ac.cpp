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
  int countNodes(TreeNode *root) {

    if (!root)
      return 0;
    int d = depth(root);

    int l = 1 << (d - 1);
    int r = (1 << d) - 1;
    cout << l << " " << r;
    int ans = l;

    while (l <= r) {
      int m = (l + r) / 2;
      if (find(root, m)) {
        ans = m;
        l = m + 1;
      } else
        r = m - 1;
    }
    return ans;
  }

  int depth(TreeNode *root) {
    if (!root)
      return 0;
    return 1 + depth(root->left);
  }

  TreeNode *find(TreeNode *root, int path) {

    stack<int> s;
    while (path) {
      s.push(path % 2);
      path /= 2;
    }

    s.pop();

    while (root && s.size()) {
      int d = s.top();
      s.pop();
      if (d)
        root = root->right;
      else
        root = root->left;
    }

    return root;
  }
};
