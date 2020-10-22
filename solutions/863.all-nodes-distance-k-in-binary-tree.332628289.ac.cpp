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
  int K;
  vector<int> ans;
  TreeNode *target;

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    this->K = K;
    this->target = target;
    dfs(root);

    return ans;
  }

  int dfs(TreeNode *root) {
    if (!root)
      return -1;
    if (root == target) {
      dfsSubtree(root);
      return 1;
    }
    int l = dfs(root->left);
    if (~l) {
      if (l == K)
        ans.push_back(root->val);
      else
        dfsSubtree(root->right, l + 1);
      return l + 1;
    }

    int r = dfs(root->right);
    if (~r) {
      if (r == K)
        ans.push_back(root->val);
      else
        dfsSubtree(root->left, r + 1);
      return r + 1;
    }

    return -1;
  }
  void dfsSubtree(TreeNode *root, int dist = 0) {
    if (!root)
      return;
    if (dist == K) {
      ans.push_back(root->val);
      return;
    }
    dfsSubtree(root->left, dist + 1);
    dfsSubtree(root->right, dist + 1);
  }
};
