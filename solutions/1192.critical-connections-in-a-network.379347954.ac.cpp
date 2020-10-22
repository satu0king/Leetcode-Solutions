class Solution {
  void dfs(int u, vector<vector<int>> &g, vector<int> &lowestAncestorTime,
           vector<int> &entryTime, int &time, vector<vector<int>> &ans,
           int parent = -1) {
    if (entryTime[u])
      return;
    entryTime[u] = ++time;
    lowestAncestorTime[u] = time;
    for (int v : g[u]) {
      if (v == parent)
        continue;
      dfs(v, g, lowestAncestorTime, entryTime, time, ans, u);
      lowestAncestorTime[u] = min(lowestAncestorTime[u], lowestAncestorTime[v]);
      if (lowestAncestorTime[v] > entryTime[u])
        ans.push_back({u, v});
    }
  }

public:
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    vector<vector<int>> g(n);
    for (auto &v : connections) {
      g[v[0]].push_back(v[1]);
      g[v[1]].push_back(v[0]);
    }
    vector<int> lowestAncestorTime(n);
    vector<int> entryTime(n);
    int time = 0;
    vector<vector<int>> ans;
    dfs(0, g, lowestAncestorTime, entryTime, time, ans);
    return ans;
  }
};
