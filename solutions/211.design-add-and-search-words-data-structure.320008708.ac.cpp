struct Trie {
  bool isWord;
  vector<Trie *> children;
  Trie() : children(26), isWord(false){};

  void addWord(string &w, int i = 0) {
    if (i == w.size()) {
      isWord = true;
      return;
    }

    int j = w[i] - 'a';
    if (!children[j])
      children[j] = new Trie();

    children[j]->addWord(w, i + 1);
  }

  bool find(string &w, int i = 0) {
    if (i == w.size())
      return isWord;

    if (w[i] == '.') {

      for (int j = 0; j < 26; j++)
        if (children[j] && children[j]->find(w, i + 1))
          return true;

      return false;
    }

    int j = w[i] - 'a';
    if (!children[j])
      return false;

    return children[j]->find(w, i + 1);
  }
};

class WordDictionary {

  Trie root;

public:
  /** Initialize your data structure here. */
  WordDictionary() {}

  /** Adds a word into the data structure. */
  void addWord(string word) { root.addWord(word); }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) { return root.find(word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
