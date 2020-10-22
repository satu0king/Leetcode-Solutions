struct Node {
  bool isWord;
  int index;
  vector<Node *> edges;

  Node() : isWord(false), edges(26, NULL), index(-1) {}

  void addWord(string &s, int ind = -1, int i = 0) {
    if (s.size() == i) {
      index = ind;
      isWord = true;
    } else {
      int c = s[i] - 'a';
      if (!edges[c])
        edges[c] = new Node();
      edges[c]->addWord(s, ind, i + 1);
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
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    Node root;
    for (int i = 0; i < wordDict.size(); i++)
      root.addWord(wordDict[i], i);

    vector<int> temp;
    vector<vector<int>> ansTemp;
    if (canBreak(s, wordDict))
      search(&root, s, ansTemp, temp);

    vector<string> ans;
    for (auto &v : ansTemp)
      ans.push_back(join(v, wordDict));
    return ans;
  }

  bool canBreak(string s, vector<string> &wordDict) {
    int n = s.size();

    set<string> dict;
    for (auto w : wordDict)
      dict.insert(w);

    vector<bool> dp(n + 1, false);
    dp[0] = true; // You can make empty string with any wordDict

    // From every i position check if you can make word ending here
    for (int i = 0; i < n; i++) {
      // If we can make a word from j->i
      // We need to check if we can make a word till j first
      for (int j = i; j >= 0; j--) {
        string curr = s.substr(j, i - j + 1); // pos,noOfChars

        if (dict.find(curr) != dict.end())
          dp[i + 1] =
              dp[i + 1] ||
              dp[j]; // dp[j] means can be make words before j(dp is 1 indexed)

        if (dp[i + 1])
          break;
      }
    }

    return dp[n];
  }

  void search(Node *root, string &s, vector<vector<int>> &ans,
              vector<int> &path, int i = 0, Node *temp = NULL) {

    if (i >= s.size())
      return;

    cout << s.size() << " ";

    bool override = true;
    if (!temp) {
      temp = root;
      override = false;
    }

    auto p = temp->find(s, i, override);

    if (!p.first)
      return;

    path.push_back(p.first->index);

    if (p.first && p.second == s.size())
      ans.push_back(path);
    else
      search(root, s, ans, path, p.second);

    path.pop_back();
    search(root, s, ans, path, p.second, p.first);
  }

  string join(vector<int> &words, vector<string> &wordDict) {
    string ans = "";
    for (int &i : words) {
      if (ans.empty())
        ans = wordDict[i];
      else
        ans += " " + wordDict[i];
    }

    return ans;
  }
};
