const int directions[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class Solution {
public:
  int maxDistance(vector<vector<int>> &grid) {
    int n = grid.size();
    if (!n)
      return -1;
    int m = grid.size();

    int dist = 0;
    int ans = -1;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          grid[i][j] = -1;
          q.emplace(i, j);
        }
      }

    while (q.size()) {
      dist++;
      int t = q.size();
      while (t--) {
        auto [i, j] = q.front();
        q.pop();

        for (auto [x, y] : directions) {
          int newI = i + x;
          int newJ = j + y;
          if (newI >= 0 && newJ >= 0 && newI < n && newJ < m &&
              ~grid[newI][newJ]) {
            grid[newI][newJ]--;
            q.emplace(newI, newJ);
          }
        }
      }

      if (q.size())
        ans = dist;
    }

    return ans;
  }
};
