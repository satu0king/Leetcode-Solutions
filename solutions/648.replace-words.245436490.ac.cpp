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

  int find(string &s, int i = 0) {

    if (isWord)
      return index;

    if (s.size() == i)
      return -1;

    int c = s[i] - 'a';
    if (!edges[c])
      return -1;
    return edges[c]->find(s, i + 1);
  }
};

class Solution {
public:
  string replaceWords(vector<string> &dict, string sentence) {
    vector<string> words = split(sentence);
    Node root;
    for (int i = 0; i < dict.size(); i++)
      root.addWord(dict[i], i);
    for (string &w : words)
      replace(w, dict, root);

    return join(words);
  }

  void replace(string &s, vector<string> &dict, Node &root) {
    int ind = root.find(s);

    // cout<<s<<endl;
    if (~ind)
      s = dict[ind];
    // cout<<s<<endl;
  }

  vector<string> split(string &s) {
    int i = 0;
    int j = 0;

    vector<string> ans;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        ans.push_back(s.substr(j, i - j));
        j = i + 1;
      }
    }

    if (i - j)
      ans.push_back(s.substr(j, i - j));

    return ans;
  }
  string join(vector<string> &words) {
    string ans = "";
    for (string &w : words) {
      if (ans.empty())
        ans = w;
      else
        ans += " " + w;
    }

    return ans;
  }
};
