struct Node {
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};

class MyLinkedList {

  Node *root;

public:
  /** Initialize your data structure here. */

  MyLinkedList() { root = new Node(-1); }

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {
    // index = max(index, 0);
    if (index < 0)
      return -1;

    Node *temp = root->next;

    while (temp) {
      if (index-- == 0)
        return temp->val;
      temp = temp->next;
    }
    return -1;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    Node *temp = root->next;
    root->next = new Node(val);
    root->next->next = temp;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {

    Node *temp = root;
    while (temp->next)
      temp = temp->next;

    temp->next = new Node(val);
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    index = max(index, 0);

    Node *temp = root;
    while (temp) {
      if (index-- == 0) {
        Node *temp2 = temp->next;
        temp->next = new Node(val);
        temp->next->next = temp2;
        return;
      }
      temp = temp->next;
    }
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {

    Node *temp = root;
    while (temp->next) {
      if (index-- == 0) {
        temp->next = temp->next->next;
        return;
      }
      temp = temp->next;
    }
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
