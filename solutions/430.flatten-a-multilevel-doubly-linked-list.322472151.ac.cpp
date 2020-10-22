/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
  Node *flatten(Node *head) {

    if (!head)
      return head;

    stack<Node *> s;
    Node *prev = NULL;

    s.push(head);

    while (s.size()) {
      auto n = s.top();
      s.pop();

      n->prev = prev;

      if (prev)
        prev->next = n;

      if (n->next)
        s.push(n->next);

      if (n->child) {
        s.push(n->child);
        n->child = NULL;
      }

      prev = n;
    }

    return head;
  }
};
