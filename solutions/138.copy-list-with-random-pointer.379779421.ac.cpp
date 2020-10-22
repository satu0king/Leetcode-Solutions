/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return head;

    Node *current = head;

    while (current) {
      Node *newCurrent = new Node(current->val);
      newCurrent->next = current->next;
      current->next = newCurrent;
      current = newCurrent->next;
    }

    current = head;

    while (current) {
      if (current->random)
        current->next->random = current->random->next;
      current = current->next->next;
    }

    Node *oldListHead = head;
    Node *newListHead = head->next;
    Node *newListHeadResult = head->next;

    while (oldListHead) {
      oldListHead->next = oldListHead->next->next;
      if (newListHead->next) {
        newListHead->next = newListHead->next->next;
      }

      oldListHead = oldListHead->next;
      newListHead = newListHead->next;
    }

    return newListHeadResult;
  }
};
