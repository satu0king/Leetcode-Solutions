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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root)
      return ans;
    vector<TreeNode *> stack = {root};

    while (!stack.empty()) {
      ans.push_back(vector<int>());
      vector<TreeNode *> tempStack;
      while (!stack.empty()) {
        auto t = stack.back();
        ans.back().push_back(t->val);
        if (ans.size() % 2 == 0) {
          if (t->right)
            tempStack.push_back(t->right);
          if (t->left)
            tempStack.push_back(t->left);
        } else {
          if (t->left)
            tempStack.push_back(t->left);
          if (t->right)
            tempStack.push_back(t->right);
        }
        stack.pop_back();
      }
      stack = move(tempStack);
    }

    return ans;
  }
};
