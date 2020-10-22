class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    if (!n)
      return 0;
    int m = grid[0].size();

    int fresh = 0;
    queue<pair<int, int>> rottenQueue;
    int ans = 0;

    int dir_x[] = {0, 0, 1, -1};
    int dir_y[] = {1, -1, 0, 0};

    for (int x = 0; x < n; x++)
      for (int y = 0; y < m; y++) {
        if (grid[x][y] == 1)
          fresh++;
        else if (grid[x][y] == 2) {
          rottenQueue.emplace(x, y);
        }
      }

    while (fresh && rottenQueue.size()) {
      int t = rottenQueue.size();
      ans++;
      while (t--) {
        auto p = rottenQueue.front();
        rottenQueue.pop();
        int x = p.first;
        int y = p.second;

        for (int i = 0; i < 4; i++) {
          int new_x = x + dir_x[i];
          int new_y = y + dir_y[i];
          if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
            if (grid[new_x][new_y] == 1) {
              fresh--;
              rottenQueue.emplace(new_x, new_y);
              grid[new_x][new_y] = 2;
            }
          }
        }
      }
    }

    return fresh ? -1 : ans;
  }
};
