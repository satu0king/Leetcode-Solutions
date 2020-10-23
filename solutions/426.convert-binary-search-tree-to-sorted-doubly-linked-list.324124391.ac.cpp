/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
  Node *treeToDoublyList(Node *root) {
    if (!root)
      return root;
    Node *dummy = new Node(0);
    Node *prev = dummy;

    f(root, prev);

    dummy->right->left = prev;
    prev->right = dummy->right;

    return dummy->right;
  }

  void f(Node *root, Node *&prev) {
    if (!root)
      return;

    f(root->left, prev);

    prev->right = root;
    root->left = prev;

    prev = root;

    f(root->right, prev);
  }
};
