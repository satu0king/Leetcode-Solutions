class Solution {
  unordered_map<int, vector<int>> x_edges;
  unordered_map<int, vector<int>> y_edges;

public:
  int removeStones(vector<vector<int>> &stones) {

    int n = stones.size();
    for (int i = 0; i < n; i++) {
      int x = stones[i][0];
      int y = stones[i][1];
      x_edges[x].push_back(i);
      y_edges[y].push_back(i);
    }
    vector<bool> visited(n);

    int connectedComponents = 0;

    for (int i = 0; i < n; i++)
      if (!visited[i]) {
        connectedComponents++;
        dfs(visited, stones, i);
      }
    return n - connectedComponents;
  }

  void dfs(vector<bool> &visited, vector<vector<int>> &stones, int i) {
    if (visited[i])
      return;
    visited[i] = true;

    for (int j : x_edges[stones[i][0]])
      dfs(visited, stones, j);

    for (int j : y_edges[stones[i][1]])
      dfs(visited, stones, j);
  }
};
