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
  TreeNode *str2tree(string s) {
    int i = 0;
    return f(s, i);
  }
  TreeNode *f(string &s, int &i) {
    if (i >= s.size())
      return NULL;

    int start = i;

    if (s[i] == '-')
      i++;

    while (i < s.size() && isdigit(s[i]))
      i++;

    TreeNode *node = new TreeNode(stoi(s.substr(start, i - start)));

    if (i < s.size() && s[i] == '(') {
      i++; // (
      node->left = f(s, i);
      i++; // )
    }
    if (i < s.size() && s[i] == '(') {
      i++; // (
      node->right = f(s, i);
      i++; // )
    }

    return node;
  }
};
