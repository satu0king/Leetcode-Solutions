class Solution {

  bool flag;
  string ans;
  unordered_set<char> visited;
  unordered_set<char> recStack;
  unordered_map<char, unordered_set<char>> graph;
  unordered_set<char> charSet;

public:
  string alienOrder(vector<string> &words) {
    flag = true;

    int n = words.size();
    charSet.insert(words[0].begin(), words[0].end());

    for (int i = 0; i < n - 1; i++) {
      auto &word1 = words[i];
      auto &word2 = words[i + 1];
      charSet.insert(word1.begin(), word1.end());
      charSet.insert(word2.begin(), word2.end());
      int m = min(word1.size(), word2.size());
      for (int j = 0; j < m; j++) {
        if (word1[j] != word2[j]) {
          graph[word1[j]].insert(word2[j]);
          break;
        }
      }
    }

    for (auto c : charSet)
      dfs(c);

    reverse(ans.begin(), ans.end());
    return flag ? ans : "";
  }

  void dfs(char c) {
    if (visited.count(c))
      return;

    if (recStack.count(c) || !flag) {
      flag = false;
      return;
    }

    recStack.insert(c);

    for (char ch : graph[c])
      dfs(ch);

    ans += c;
    visited.insert(c);
    recStack.erase(c);
  }
};
