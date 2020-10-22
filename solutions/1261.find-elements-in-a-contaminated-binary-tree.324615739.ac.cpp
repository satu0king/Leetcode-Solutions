/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
  TreeNode *root;
  unordered_set<int> set;

public:
  FindElements(TreeNode *root) : root(root) { f(root); }

  void f(TreeNode *root, int x = 0) {
    if (!root)
      return;
    root->val = x;
    set.insert(x);
    f(root->left, 2 * x + 1);
    f(root->right, 2 * x + 2);
  }

  bool find(int target) { return set.count(target); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
