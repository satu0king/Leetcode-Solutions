class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    queue<vector<int>> q;
    int ans = 1;
    int n = grid.size();
    if (grid[0][0])
      return -1;
    q.push({0, 0});
    grid[0][0] = 1;

    while (q.size()) {
      int m = q.size();
      while (m--) {
        auto p = q.front();
        q.pop();
        if (p[0] == n - 1 && p[1] == n - 1)
          return ans;

        for (int i = -1; i < 2; i++)
          for (int j = -1; j < 2; j++) {
            if (p[0] + i < 0 || p[1] + j < 0 || p[0] + i > n - 1 ||
                p[1] + j > n - 1)
              continue;
            if (grid[p[0] + i][p[1] + j])
              continue;
            grid[p[0] + i][p[1] + j] = 1;
            q.push({p[0] + i, p[1] + j});
          }
      }

      ans++;
    }

    return -1;
  }
};
