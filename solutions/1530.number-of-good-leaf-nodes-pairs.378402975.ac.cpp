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
  int countPairs(TreeNode *root, int distance) {
    int ans = 0;
    if (!root)
      return ans;
    f(root, distance, ans);
    return ans;
  }
  vector<int> f(TreeNode *root, int distance, int &ans, int depth = 0) {
    if (root->left && root->right) {
      auto leftPoints = f(root->left, distance, ans, depth + 1);
      auto rightPoints = f(root->right, distance, ans, depth + 1);
      int r = rightPoints.size() - 1;

      for (int i = 0; i < leftPoints.size(); i++) {
        int leftD = leftPoints[i] - depth;
        while (r >= 0 && leftD + rightPoints[r] - depth > distance)
          r--;
        ans += r + 1;
      }

      vector<int> result;
      int i = 0;
      int j = 0;
      while (i < leftPoints.size() || j < rightPoints.size()) {
        if (i == leftPoints.size())
          result.push_back(rightPoints[j++]);
        else if (j == rightPoints.size())
          result.push_back(leftPoints[i++]);
        else if (leftPoints[i] < rightPoints[j])
          result.push_back(leftPoints[i++]);
        else
          result.push_back(rightPoints[j++]);
      }
      while (result.size() && result.back() - depth >= distance)
        result.pop_back();
      return result;
    } else if (root->left) {
      return f(root->left, distance, ans, depth + 1);
    } else if (root->right) {
      return f(root->right, distance, ans, depth + 1);
    } else {
      return {depth};
    }
  }
};
