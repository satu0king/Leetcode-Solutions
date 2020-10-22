class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
    vector<int> dist(n, -1);
    dist[src] = 0;
    K++;
    while (K--) {
      vector<int> newDist = dist;
      for (auto &edge : flights) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (dist[u] != -1) {
          if (newDist[v] == -1 || dist[u] + w < newDist[v]) {
            newDist[v] = dist[u] + w;
          }
        }
      }
      dist = move(newDist);
    }
    return dist[dst];
  }
};
