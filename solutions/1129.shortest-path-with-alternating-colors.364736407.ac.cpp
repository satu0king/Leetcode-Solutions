class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges,
                                       vector<vector<int>> &blue_edges) {
    vector<vector<bool>> visited(n, vector<bool>(2));
    queue<pair<int, bool>> q;
    vector<vector<int>> redG(n);
    vector<vector<int>> blueG(n);
    for (auto &v : red_edges)
      redG[v[0]].push_back(v[1]);
    for (auto &v : blue_edges)
      blueG[v[0]].push_back(v[1]);
    q.emplace(0, false);
    q.emplace(0, true);
    visited[0][0] = true;
    visited[0][1] = true;
    vector<int> ans(n, INT_MAX);
    int dist = 0;
    while (q.size()) {
      int t = q.size();
      while (t--) {
        auto p = q.front();
        q.pop();
        int i = p.first;
        bool c = p.second;
        ans[i] = min(ans[i], dist);
        auto &g = c ? redG : blueG;
        c = !c;
        for (int j : g[i]) {
          if (!visited[j][c]) {
            visited[j][c] = true;
            q.emplace(j, c);
          }
        }
      }
      dist++;
    }
    for (int &a : ans)
      if (a == INT_MAX)
        a = -1;
    return ans;
  }
};
