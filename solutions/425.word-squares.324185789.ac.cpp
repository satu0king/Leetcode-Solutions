struct Node {
  vector<Node *> edges;
  Node() : edges(26, NULL) {}

  void insert(string &w, int i = 0) {
    if (i == w.size())
      return;

    int c = w[i] - 'a';
    if (!edges[c])
      edges[c] = new Node();
    edges[c]->insert(w, i + 1);
  }

  Node *get(char c) { return edges[c - 'a']; }

  ~Node() {
    for (auto edge : edges)
      if (edge)
        delete edge;
  }
};

class Solution {
public:
  vector<vector<string>> wordSquares(vector<string> &words) {
    Node *root = new Node();
    for (auto &w : words)
      root->insert(w);

    vector<vector<string>> ans;

    int n = words[0].size();

    vector<string> path(n, string(n, ' '));

    f(ans, root, root, path);

    // delete root;

    return ans;
  }

  void f(vector<vector<string>> &ans, Node *root, Node *current,
         vector<string> &path, int i = 0, int j = 0) {
    int n = path.size();

    if (!current)
      return;

    if (i == n) {
      ans.push_back(path);
      return;
    }

    if (j == n) {
      f(ans, root, root, path, i + 1);
      return;
    }

    while (j < i && current) {
      path[i][j] = path[j][i];
      current = current->get(path[j++][i]);
    }

    if (!current)
      return;

    for (char c = 'a'; c <= 'z'; c++) {
      path[i][j] = c;
      f(ans, root, current->get(c), path, i, j + 1);
    }
  }
};
