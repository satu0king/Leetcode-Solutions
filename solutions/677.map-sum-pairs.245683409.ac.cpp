struct Node {
  bool isWord;
  int value;
  vector<Node *> edges;

  Node() : isWord(false), edges(256, NULL), value(-1) {}

  void addWord(string &s, int v = -1, int i = 0) {
    if (s.size() == i) {
      value = v;
      isWord = true;
    } else {
      int c = s[i];
      if (!edges[c])
        edges[c] = new Node();
      edges[c]->addWord(s, v, i + 1);
    }
  }

  int find(string &s, int i = 0) {

    if (s.size() == i)
      return sum();

    int c = s[i];
    if (!edges[c])
      return 0;
    return edges[c]->find(s, i + 1);
  }

  int sum() {
    int ans = 0;
    if (isWord)
      ans += value;

    for (int i = 0; i < 256; i++)
      if (edges[i])
        ans += edges[i]->sum();

    return ans;
  }
};

class MapSum {
public:
  /** Initialize your data structure here. */

  Node *root;
  MapSum() { root = new Node(); }

  void insert(string key, int val) { root->addWord(key, val); }

  int sum(string prefix) { return root->find(prefix); }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
