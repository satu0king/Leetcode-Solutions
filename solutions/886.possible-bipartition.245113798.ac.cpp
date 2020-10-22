class Solution {
public:
  bool possibleBipartition(int N, vector<vector<int>> &dislikes) {

    vector<vector<int>> g(N + 1);

    for (auto v : dislikes) {
      g[v[0]].push_back(v[1]);
      g[v[1]].push_back(v[0]);
    }
    vector<int> coloring(N + 1, -1);

    for (int i = 1; i <= N; i++)
      if (coloring[i] == -1 && !dfs(g, coloring, i))
        return false;

    return true;
  }

  bool dfs(vector<vector<int>> &g, vector<int> &coloring, int i,
           int color = 0) {
    if (~coloring[i])
      return coloring[i] == color;

    coloring[i] = color;
    for (int j : g[i]) {
      if (!dfs(g, coloring, j, (color + 1) % 2))
        return false;
    }

    return true;
  }
};
