class Node {
  bool isWord;
  unordered_map<char, Node *> mp;

public:
  Node() : isWord(false) {}
  void addWord(string &word, int i = 0) {
    if (i == word.size()) {
      isWord = true;
      return;
    }

    if (mp.find(word[i]) == mp.end())
      mp[word[i]] = new Node();
    mp[word[i]]->addWord(word, i + 1);
  }
  int search(string &word, int i = 0) {
    if (i == word.size())
      return isWord;

    if (mp.find(word[i]) == mp.end())
      return -1;
    return mp[word[i]]->search(word, i + 1);
  }
};

class Trie {
  Node *root;

public:
  /** Initialize your data structure here. */
  Trie() : root(new Node()) {}

  /** Inserts a word into the trie. */
  void insert(string word) { root->addWord(word); }

  /** Returns if the word is in the trie. */
  bool search(string word) { return root->search(word) == 1; }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) { return ~root->search(prefix); }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
