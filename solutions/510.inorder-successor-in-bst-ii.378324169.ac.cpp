/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
  Node *inorderSuccessor(Node *node) {
    Node *ans = node->right;
    while (ans && ans->left) {
      ans = ans->left;
    }
    if (ans)
      return ans;
    while (node->parent) {
      if (node->parent->left == node)
        break;
      node = node->parent;
    }
    if (!node->parent)
      return NULL;
    return node->parent;
  }
};
