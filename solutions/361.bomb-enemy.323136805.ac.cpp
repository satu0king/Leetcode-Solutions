class Solution {
public:
  int maxKilledEnemies(vector<vector<char>> &grid) {
    int n = grid.size();
    if (!n)
      return 0;
    int m = grid[0].size();
    vector<vector<int>> score(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      int t = 0;
      for (int j = 0; j < m - 1; j++) {
        if (grid[i][j] == 'W')
          t = 0;
        else if (grid[i][j] == 'E')
          t++;
        score[i][j + 1] += t;
      }
      t = 0;
      for (int j = m - 1; j >= 1; j--) {
        if (grid[i][j] == 'W')
          t = 0;
        else if (grid[i][j] == 'E')
          t++;
        score[i][j - 1] += t;
      }
    }

    for (int j = 0; j < m; j++) {
      int t = 0;
      for (int i = 0; i < n - 1; i++) {
        if (grid[i][j] == 'W')
          t = 0;
        else if (grid[i][j] == 'E')
          t++;
        score[i + 1][j] += t;
      }
      t = 0;
      for (int i = n - 1; i >= 1; i--) {
        if (grid[i][j] == 'W')
          t = 0;
        else if (grid[i][j] == 'E')
          t++;
        score[i - 1][j] += t;
      }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[i][j] == '0')
          ans = max(ans, score[i][j]);

    return ans;
  }
};
