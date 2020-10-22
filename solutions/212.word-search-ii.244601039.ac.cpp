struct Node {
  bool isWord;
  int wordIndex;
  vector<Node *> nodeList;

  Node() : isWord(false), wordIndex(-1), nodeList(26, NULL){};

  void addWord(string &w, int wordIndex = -1, int i = 0) {
    if (w.size() == i) {
      isWord = true;
      this->wordIndex = wordIndex;
      return;
    }

    char c = w[i] - 'a';
    if (!nodeList[c])
      nodeList[c] = new Node();

    nodeList[c]->addWord(w, wordIndex, i + 1);
  }

  Node *find(char c) {
    if (c == '#')
      return NULL;
    return nodeList[c - 'a'];
  }
};

class Solution {

  Node root;

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    vector<string> ans;
    int w = words.size();

    for (int i = 0; i < w; i++)
      root.addWord(words[i], i);

    int n = board.size();
    if (!n)
      return ans;
    int m = board[0].size();

    unordered_set<string> temp;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        dfs(board, words, temp, i, j, &root);

    ans.insert(ans.end(), temp.begin(), temp.end());

    return ans;
  }

  void dfs(vector<vector<char>> &board, vector<string> &words,
           unordered_set<string> &ans, int i, int j, Node *root) {
    int n = board.size();
    int m = board[0].size();

    if (i < 0 or j < 0 or i >= n or j >= m)
      return;
    if (board[i][j] == '#')
      return;

    char c = board[i][j];
    board[i][j] = '#';
    Node *temp = root->find(c);
    if (temp && temp->isWord)
      ans.insert(words[temp->wordIndex]);

    if (temp) {
      dfs(board, words, ans, i + 1, j, temp);
      dfs(board, words, ans, i - 1, j, temp);
      dfs(board, words, ans, i, j + 1, temp);
      dfs(board, words, ans, i, j - 1, temp);
    }

    board[i][j] = c;
  }
};
