/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left),
 * right(right), random(random) {}
 * };
 */

class Solution {
  unordered_map<Node *, NodeCopy *> mp;

public:
  NodeCopy *copyRandomBinaryTree(Node *root) {
    if (!root)
      return NULL;
    if (mp[root])
      return mp[root];
    auto temp = new NodeCopy(root->val);
    mp[root] = temp;
    temp->left = copyRandomBinaryTree(root->left);
    temp->right = copyRandomBinaryTree(root->right);
    temp->random = copyRandomBinaryTree(root->random);
    return temp;
  }
};
