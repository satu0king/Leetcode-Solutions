/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
  TreeNode *root;
  queue<TreeNode *> q;

public:
  CBTInserter(TreeNode *root) : root(root) {

    queue<TreeNode *> temp;
    temp.push(root);

    while (temp.size()) {

      auto p = temp.front();
      temp.pop();
      if (!p->right)
        q.push(p);

      if (p->left)
        temp.push(p->left);
      if (p->right)
        temp.push(p->right);
    }
  }

  int insert(int v) {

    TreeNode *temp = new TreeNode(v);
    auto p = q.front();

    if (!p->left)
      p->left = temp;
    else {
      p->right = temp;
      q.pop();
    }

    q.push(temp);

    return p->val;
  }

  TreeNode *get_root() { return root; }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
