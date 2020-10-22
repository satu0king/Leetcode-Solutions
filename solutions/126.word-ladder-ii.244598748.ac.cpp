class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {

    unordered_map<string, int> map;

    wordList.push_back(beginWord);

    int n = wordList.size();
    for (int i = 0; i < n; i++)
      map[wordList[i]] = i;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {

      string &word = wordList[i];
      string temp = word;
      for (int j = 0; j < word.size(); j++) {

        for (char c = 'a'; c <= 'z'; c++) {
          temp[j] = c;
          if (map.count(temp) && map[temp] != i)
            graph[i].push_back(map[temp]);
        }
        temp[j] = word[j];
      }
    }

    vector<bool> visited(n);
    queue<pair<int, vector<int>>> q;
    q.emplace(n - 1, vector<int>{n - 1});

    vector<vector<string>> ans;

    while (q.size()) {
      int s = q.size();

      vector<pair<int, vector<int>>> list;

      bool flag = false;
      for (int i = 0; i < s; i++) {
        list.push_back(q.front());
        q.pop();
        visited[list.back().first] = true;
        if (wordList[list.back().first] == endWord) {
          flag = true;
          ans.push_back(getAnswer(list.back().second, wordList));
        }
      }

      if (flag)
        break;

      for (auto &p : list) {
        for (int j : graph[p.first]) {
          if (!visited[j]) {
            q.emplace(j, p.second);
            q.back().second.push_back(j);
          }
        }
      }
    }

    return ans;
  }

  vector<string> getAnswer(vector<int> &l, vector<string> &wordList) {
    vector<string> res;
    for (int i : l)
      res.push_back(wordList[i]);
    return res;
  }
};
