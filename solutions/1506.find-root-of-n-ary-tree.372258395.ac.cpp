/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  Node *findRoot(vector<Node *> tree) {
    unordered_set<Node *> leftNodes(tree.begin(), tree.end());
    for (auto root : tree)
      dfs(leftNodes, root);
    return *leftNodes.begin();
  }

  void dfs(unordered_set<Node *> &leftNodes, Node *root) {
    if (!root || !leftNodes.count(root))
      return;
    for (auto child : root->children) {
      dfs(leftNodes, child);
      leftNodes.erase(child);
    }
  }
};
