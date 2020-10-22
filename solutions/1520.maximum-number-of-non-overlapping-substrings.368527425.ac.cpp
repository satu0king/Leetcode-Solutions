class Solution {
public:
  vector<string> maxNumOfSubstrings(string s) {
    vector<int> start(256, -1);
    vector<int> end(256, -1);
    vector<int> effectiveStart(256, -1);
    vector<int> effectiveEnd(256, -1);
    for (int i = 0; i < s.size(); i++) {
      if (start[s[i]] == -1)
        start[s[i]] = i;
      end[s[i]] = i;
    }
    vector<vector<int>> g(256);
    vector<char> candidates;
    for (char a = 'a'; a <= 'z'; a++) {
      if (~start[a]) {
        vector<bool> visited(256);
        candidates.push_back(a);
        for (int i = start[a]; i <= end[a]; i++) {
          if (s[i] != a && !visited[s[i]]) {
            g[a].push_back(s[i]);
            visited[s[i]] = true;
          }
        }
      }
    }

    vector<pair<int, int>> v;

    for (auto a : candidates) {
      vector<bool> visited(256);
      int l = s.size();
      int r = -1;
      dfs(g, a, visited, l, r, start, end);
      v.emplace_back(l, r);
    }

    sort(v.begin(), v.end());
    vector<pair<int, int>> selected;
    for (auto &e : v) {
      // cout << e.first <<" " << e.second << endl;
      if (selected.empty())
        selected.push_back(e);
      else if (e.first > selected.back().second)
        selected.push_back(e);
      else if (e.second < selected.back().second) {
        selected.pop_back();
        selected.push_back(e);
      }
    }
    vector<string> ans;
    for (auto e : selected)
      ans.push_back(s.substr(e.first, e.second - e.first + 1));
    return ans;
  }

  void dfs(vector<vector<int>> &g, char a, vector<bool> &visited, int &l,
           int &r, vector<int> &start, vector<int> &end) {
    if (visited[a])
      return;
    visited[a] = true;
    l = min(l, start[a]);
    r = max(r, end[a]);
    for (char b : g[a])
      dfs(g, b, visited, l, r, start, end);
  }
};
