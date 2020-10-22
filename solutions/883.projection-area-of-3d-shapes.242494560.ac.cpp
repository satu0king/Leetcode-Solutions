class Solution {
public:
  int projectionArea(vector<vector<int>> &grid) {
    int area = 0;

    int n = grid.size();
    if (!n)
      return area;
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[i][j])
          area++;

    for (int i = 0; i < n; i++) {
      int mx = 0;
      for (int j = 0; j < m; j++)
        mx = max(grid[i][j], mx);
      area += mx;
    }
    for (int j = 0; j < m; j++) {
      int mx = 0;
      for (int i = 0; i < n; i++)
        mx = max(grid[i][j], mx);
      area += mx;
    }

    return area;
  }
};
