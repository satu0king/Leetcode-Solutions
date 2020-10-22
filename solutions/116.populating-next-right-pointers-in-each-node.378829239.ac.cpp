/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

// THIS SOLUTION IS WRONGG
// THIS SOLUTION IS WRONGG
// THIS SOLUTION IS WRONGG
// THIS SOLUTION IS WRONGG

class Solution {
public:
  Node *connect(Node *root) {

    Node *current = root;
    while (current) {
      Node *nextLevelFirstNode = NULL;
      Node *prev = NULL;
      while (current) {
        if (current->left) {
          if (!nextLevelFirstNode)
            nextLevelFirstNode = current->left;
          if (prev)
            prev->next = current->left;
          prev = current->left;
        }
        if (current->right) {
          if (!nextLevelFirstNode)
            nextLevelFirstNode = current->right;
          if (prev)
            prev->next = current->right;
          prev = current->right;
        }
        current = current->next;
      }
      current = nextLevelFirstNode;
    }
    return root;
  }
};
