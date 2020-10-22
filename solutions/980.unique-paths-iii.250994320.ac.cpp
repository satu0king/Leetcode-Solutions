

class Solution {

public:
  int uniquePathsIII(vector<vector<int>> &grid) {

    int n1 = grid.size();
    if (!n1)
      return 0;
    int n2 = grid[0].size();

    int start_i, start_j;
    int left = 0;

    for (int i = 0; i < n1; i++)
      for (int j = 0; j < n2; j++) {
        if (grid[i][j] == 1) {
          start_i = i;
          start_j = j;
        } else if (grid[i][j] == 0)
          left++;
      }

    return dfs(start_i, start_j, left, grid);
  }

  int dfs(int i, int j, int left, vector<vector<int>> &grid) {
    int n1 = grid.size();
    int n2 = grid[0].size();

    if (i < 0 or j < 0 or i >= n1 or j >= n2)
      return 0;

    int ans = 0;

    if (~grid[i][j]) {

      if (grid[i][j] == 2) {
        if (left == 0)
          ans = 1;
      } else {
        if (grid[i][j] == 0)
          left--;

        int temp = grid[i][j];
        grid[i][j] = -1;
        ans += dfs(i + 1, j, left, grid);
        ans += dfs(i - 1, j, left, grid);
        ans += dfs(i, j + 1, left, grid);
        ans += dfs(i, j - 1, left, grid);
        grid[i][j] = temp;
      }
    }

    return ans;
  }
};
