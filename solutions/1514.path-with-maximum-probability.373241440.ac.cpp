class Solution {
public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start, int end) {

    vector<vector<pair<int, double>>> g(n);
    for (int i = 0; i < edges.size(); i++) {
      g[edges[i][0]].push_back({edges[i][1], succProb[i]});
      g[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    vector<double> dist(n);
    dist[start] = 1;
    priority_queue<pair<double, int>> pq;
    pq.push({1, start});
    while (pq.size()) {
      auto [p, u] = pq.top();
      pq.pop();
      if (u == end)
        return p;
      for (auto [v, w] : g[u]) {
        if (dist[v] < w * p) {
          dist[v] = w * p;
          pq.push({dist[v], v});
        }
      }
    }

    return 0;
  }
};
