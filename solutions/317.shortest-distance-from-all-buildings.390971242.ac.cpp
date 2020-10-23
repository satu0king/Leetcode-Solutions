const int directions[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class Solution {
public:
  int shortestDistance(vector<vector<int>> &grid) {
    int walk = 0;
    int n = grid.size();
    if (!n)
      return -1;
    int m = grid[0].size();

    int ans = -1;

    auto dist = grid;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          ans = -1;
          int d = 0;
          queue<pair<int, int>> q;
          q.emplace(i, j);
          while (q.size()) {
            d++;
            int t = q.size();
            while (t--) {
              auto [ii, jj] = q.front();
              q.pop();
              for (auto [x, y] : directions) {
                int i = ii + x;
                int j = jj + y;

                if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == walk) {
                  grid[i][j]--;
                  dist[i][j] += d;
                  q.emplace(i, j);
                  if (ans < 0 || ans > dist[i][j])
                    ans = dist[i][j];
                }
              }
            }
          }
          if (ans == -1)
            return ans;
          walk--;
        }
      }

    return ans;
  }
};
