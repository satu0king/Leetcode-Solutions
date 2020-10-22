/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
  vector<int> preorder(Node *root) {
    vector<Node *> stack;
    vector<int> ans;
    if (root)
      stack.push_back(root);
    while (stack.size()) {
      ans.push_back(stack.back()->val);
      auto &v = stack.back()->children;
      stack.pop_back();
      stack.insert(stack.end(), v.rbegin(), v.rend());
    }
    return ans;
  }
};
