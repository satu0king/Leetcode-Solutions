class Solution {
  vector<vector<int>> g;
  vector<int> longestPath;

public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    g.resize(n);

    vector<int> degree(n);
    vector<bool> visited(n);

    for (auto v : edges) {
      g[v[0]].push_back(v[1]);
      g[v[1]].push_back(v[0]);
      degree[v[0]]++;
      degree[v[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
      if (degree[i] == 1)
        q.push(i);

    int t = n;
    while (t > 2 && q.size()) {
      int count = q.size();
      while (count--) {
        int u = q.front();
        q.pop();
        visited[u] = true;
        degree[u]--;
        t--;
        for (int v : g[u]) {
          if (degree[v]) {
            degree[v]--;
            if (degree[v] == 1) {
              q.push(v);
            }
          }
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
      if (!visited[i])
        ans.push_back(i);
    return ans;
  }
};
