class Solution {
public:
  bool leadsToDestination(int n, vector<vector<int>> &edges, int source,
                          int destination) {
    vector<int> visited(n, -1);
    vector<vector<int>> g(n);
    for (auto &v : edges)
      g[v[0]].push_back(v[1]);
    return dfs(g, visited, source, destination);
  }

  int dfs(vector<vector<int>> &g, vector<int> &visited, int source,
          int destination) {
    if (~visited[source])
      return visited[source];
    visited[source] = 0;
    int ans = 0;
    if (source == destination)
      ans = 1;
    if (g[source].size()) {
      ans = 1;
      for (int j : g[source])
        ans = ans & dfs(g, visited, j, destination);
    }
    return visited[source] = ans;
  }
};
