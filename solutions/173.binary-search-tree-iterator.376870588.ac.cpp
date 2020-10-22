/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  stack<TreeNode *> s;

public:
  BSTIterator(TreeNode *root) { leftInorder(root); }

  void leftInorder(TreeNode *root) {
    while (root) {
      s.push(root);
      root = root->left;
    }
  }

  /** @return the next smallest number */
  int next() {
    auto node = s.top();
    s.pop();
    if (node->right)
      leftInorder(node->right);
    return node->val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return s.size(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
