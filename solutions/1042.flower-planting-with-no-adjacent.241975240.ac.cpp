class Solution {
public:
  vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {
    vector<vector<int>> g(N);
    for (auto path : paths) {
      g[path[0] - 1].push_back(path[1] - 1);
      g[path[1] - 1].push_back(path[0] - 1);
    }
    vector<int> visited(N);

    for (int i = 0; i < N; i++)
      dfs(i, g, visited);

    return visited;
  }

  int dfs(int i, vector<vector<int>> &g, vector<int> &visited) {

    if (visited[i])
      return visited[i];

    unordered_set<int> flowers = {1, 2, 3, 4};

    for (auto j : g[i])
      flowers.erase(visited[j]);

    visited[i] = *flowers.begin();

    return visited[i];
  }
};
