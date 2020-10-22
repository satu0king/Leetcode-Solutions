/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    if (!root)
      return NULL;
    vector<Node *> curr = {root};
    while (!curr.empty()) {
      int n = curr.size();
      for (int i = 0; i < n - 1; i++) {
        curr[i]->next = curr[i + 1];
      }
      vector<Node *> nxt;
      for (int i = 0; i < n; i++) {
        if (curr[i]->left) {
          nxt.push_back(curr[i]->left);
        }
        if (curr[i]->right) {
          nxt.push_back(curr[i]->right);
        }
      }
      swap(nxt, curr);
    }
    return root;
  }
};
