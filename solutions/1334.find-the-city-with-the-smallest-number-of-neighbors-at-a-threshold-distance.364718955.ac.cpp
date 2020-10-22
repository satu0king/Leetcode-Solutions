class Solution {
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
    vector<vector<int>> dis(n, vector<int>(n, INT_MAX / 2));
    for (int i = 0; i < n; ++i)
      dis[i][i] = 0;
    for (auto &edge : edges)
      dis[edge[0]][edge[1]] = dis[edge[1]][edge[0]] = edge[2];

    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    int minCities = n;
    int ans = -1;
    for (int i = 0; i < n; i++) {
      int c = 0;
      for (int j = 0; j < n; j++)
        if (dis[i][j] <= distanceThreshold)
          c++;
      if (c <= minCities) {
        ans = i;
        minCities = c;
      }
    }
    return ans;
  }
};
