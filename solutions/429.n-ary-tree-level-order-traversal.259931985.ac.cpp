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
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> ans;
    if (!root)
      return {};
    queue<Node *> q;
    q.push(root);

    while (q.size()) {
      int count = q.size();
      vector<int> level;
      while (count--) {
        auto temp = q.front();
        q.pop();
        level.push_back(temp->val);
        for (auto child : temp->children)
          q.push(child);
      }
      ans.push_back(level);
    }

    return ans;
  }
};
