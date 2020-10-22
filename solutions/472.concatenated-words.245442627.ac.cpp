struct Node {
  bool isWord;
  vector<Node *> edges;

  Node() : isWord(false), edges(26, NULL) {}

  void addWord(string &s, int i = 0) {
    if (s == "")
      return;
    if (s.size() == i) {
      isWord = true;
    } else {
      int c = s[i] - 'a';
      if (!edges[c])
        edges[c] = new Node();
      edges[c]->addWord(s, i + 1);
    }
  }

  pair<Node *, int> find(string &s, int i = 0, bool override = false) {

    if (isWord && !override)
      return make_pair(this, i);

    if (s.size() == i)
      return make_pair((Node *)NULL, -1);

    int c = s[i] - 'a';
    if (!edges[c])
      return make_pair((Node *)NULL, -1);
    return edges[c]->find(s, i + 1);
  }
};

class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    Node root;
    for (auto &w : words)
      root.addWord(w);

    vector<string> ans;
    for (string &w : words) {
      if (f(w, &root))
        ans.push_back(w);
    }

    return ans;
  }

  bool f(string &s, Node *mainRoot, int i = 0, bool flag = false,
         Node *tempRoot = NULL) {

    if (s == "")
      return false;

    bool override = true;
    if (!tempRoot) {
      tempRoot = mainRoot;
      override = false;
    }

    auto p = tempRoot->find(s, i, override);
    if (!p.first)
      return false;
    if (p.first && p.second == s.size())
      return flag;

    if (f(s, mainRoot, p.second, true))
      return true;

    return f(s, mainRoot, p.second, flag, p.first);
  }
};
