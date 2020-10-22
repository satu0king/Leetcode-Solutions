class Solution {
public:
  vector<vector<pair<int, int>>> g;
  int networkDelayTime(vector<vector<int>> &times, int N, int K) {
    vector<bool> vis(N + 1);
    g.resize(N + 1);

    for (auto &p : times)
      g[p[0]].emplace_back(p[1], p[2]);

    set<pair<int, int>> st;
    st.insert(make_pair(0, K));
    int tim = 0;
    int cnt = 0;
    while (!st.empty()) {
      auto value = (*st.begin());
      st.erase(value);
      int i = value.second;
      if (vis[i])
        continue;
      tim = value.first;
      vis[i] = true;
      cnt++;
      for (auto edge : g[i]) {
        if (!vis[edge.first])
          st.insert(make_pair(edge.second + tim, edge.first));
      }
    }
    if (cnt == N)
      return tim;
    else
      return -1;
  }
};
