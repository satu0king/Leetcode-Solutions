class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> coloring(n, -1);

    for (int i = 0; i < n; i++)
      if (coloring[i] == -1)
        if (!dfs(graph, coloring, i, 0))
          return false;

    return true;
  }

  bool dfs(vector<vector<int>> &graph, vector<int> &coloring, int i,
           int color) {
    if (~coloring[i])
      return coloring[i] == color;

    coloring[i] = color;

    for (int e : graph[i])
      if (!dfs(graph, coloring, e, (color + 1) % 2))
        return false;
    return true;
  }
};
