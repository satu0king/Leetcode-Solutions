class Solution {
public:
  int minCostToSupplyWater(int n, vector<int> &wells,
                           vector<vector<int>> &pipes) {
    vector<vector<pair<int, int>>> g(n);
    for (auto p : pipes) {
      int u = p[0];
      int v = p[1];
      u--;
      v--;
      g[u].emplace_back(v, p[2]);
      g[v].emplace_back(u, p[2]);
    }

    vector<bool> done(n);
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (int i = 0; i < n; i++) {
      pq.emplace(wells[i], i);
    }
    // cout << pq.size() << endl;
    while (pq.size()) {
      auto well = pq.top();
      pq.pop();
      int u = well.second;
      if (done[u])
        continue;
      done[u] = true;
      ans += well.first;
      // cout << u << " " << well.first << endl;
      for (auto pipe : g[u]) {
        int v = pipe.first;
        int w = pipe.second;
        if (done[v])
          continue;
        if (w < wells[v]) {
          pq.emplace(w, v);
        }
      }
      // cout << ans << endl;
    }

    return ans;
  }
};
