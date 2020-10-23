struct Node {
  vector<Node *> edges;
  bool isWord;
  Node() : isWord(false), edges(26, NULL) {}

  void insert(string &w, int i = 0) {
    if (i == w.size()) {
      isWord = true;
      return;
    }
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
  vector<vector<int>> indexPairs(string text, vector<string> &words) {
    Node *root = new Node();
    for (auto &w : words)
      root->insert(w);

    vector<vector<int>> ans;

    for (int i = 0; i < text.size(); i++) {

      Node *temp = root;
      for (int j = i; j < text.size(); j++) {
        temp = temp->get(text[j]);
        if (!temp)
          break;
        if (temp->isWord)
          ans.push_back({i, j});
      }
    }

    return ans;
  }
};
