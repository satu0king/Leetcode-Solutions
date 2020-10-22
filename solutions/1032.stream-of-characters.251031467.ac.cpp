struct Node {
  bool isWord;
  vector<Node *> edges;
  Node() : isWord(false), edges(26, NULL) {}
};

void addWord(string &s, Node *root) {

  reverse(s.begin(), s.end());

  for (char c : s) {
    if (!root->edges[c - 'a'])
      root->edges[c - 'a'] = new Node();
    root = root->edges[c - 'a'];
  }

  root->isWord = true;
}

bool search(string &s, Node *root) {
  int n = s.size();
  for (int i = n - 1; i >= 0; i--) {
    int c = s[i] - 'a';
    if (!root->edges[c])
      return false;
    root = root->edges[c];
    if (root->isWord)
      return true;
  }

  return false;
}

class StreamChecker {

  vector<Node *> current;
  Node *root;
  string s;

public:
  StreamChecker(vector<string> &words) {
    root = new Node();
    for (string &w : words)
      addWord(w, root);
  }

  bool query(char letter) {
    s += letter;
    return search(s, root);
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
