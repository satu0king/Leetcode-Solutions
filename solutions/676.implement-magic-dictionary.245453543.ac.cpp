struct Node {
  bool isWord;
  vector<Node *> edges;

  Node() : isWord(false), edges(26, NULL){};

  void addWord(string &w, int i = 0) {
    if (w.size() == i) {
      isWord = true;
      return;
    }

    char c = w[i] - 'a';
    if (!edges[c])
      edges[c] = new Node();

    edges[c]->addWord(w, i + 1);
  }

  Node *find(char c) { return edges[c - 'a']; }

  ~Node() {
    for (auto node : edges)
      if (node)
        delete node;
  }
};

class MagicDictionary {

  Node *root;

public:
  /** Initialize your data structure here. */
  MagicDictionary() : root(NULL) {}

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    if (root)
      delete root;
    root = new Node();
    for (string &w : dict)
      root->addWord(w);
  }

  /** Returns if there is any word in the trie that equals to the given word
   * after modifying exactly one character */
  bool search(string word) { return _search(word); }
  bool _search(string &word, int i = 0, bool flag = false, Node *root = NULL) {
    if (!root)
      root = this->root;

    if (i == word.size())
      return flag && root->isWord;

    Node *temp = root->find(word[i]);

    if (!temp && flag)
      return false;

    if (temp && _search(word, i + 1, flag, temp))
      return true;

    if (!flag) {
      for (char c = 'a'; c <= 'z'; c++) {
        if (c == word[i])
          continue;
        temp = root->find(c);
        if (temp && _search(word, i + 1, true, temp))
          return true;
      }
    }

    return false;
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
