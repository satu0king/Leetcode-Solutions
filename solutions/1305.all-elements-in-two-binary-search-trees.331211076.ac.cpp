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
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    TreeNode *c1 = root1;
    TreeNode *c2 = root2;

    vector<int> ans;

    while (c1 || c2 || s1.size() || s2.size()) {
      while (c1) {
        s1.push(c1);
        c1 = c1->left;
      }
      while (c2) {
        s2.push(c2);
        c2 = c2->left;
      }

      if (s2.empty() || (s1.size() && s1.top()->val <= s2.top()->val)) {
        c1 = s1.top();
        s1.pop();
        ans.push_back(c1->val);
        c1 = c1->right;
      } else {
        c2 = s2.top();
        s2.pop();
        ans.push_back(c2->val);
        c2 = c2->right;
      }
    }

    return ans;
  }
};
