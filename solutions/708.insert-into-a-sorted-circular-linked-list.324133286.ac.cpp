/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
  Node *insert(Node *head, int insertVal) {
    if (head == NULL) {
      auto n = new Node(insertVal);
      n->next = n;
      return n;
    }

    Node *prev = head;
    Node *next = head->next;

    while (true) {
      bool toInsert = false;

      if (prev->val <= insertVal && insertVal <= next->val)
        toInsert = true;
      else if (prev->val > next->val &&
               (insertVal > prev->val || insertVal < next->val))
        toInsert = true;

      if (next == head)
        toInsert = true;

      if (toInsert) {
        prev->next = new Node(insertVal, next);
        return prev;
      }

      prev = next;
      next = next->next;
    }
    return NULL;
  }
};
