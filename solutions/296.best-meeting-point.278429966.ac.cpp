class Solution {
public:
  int minTotalDistance(vector<vector<int>> &grid) {
    vector<int> x;
    vector<int> y;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[i][j])
          x.push_back(i);

    for (int j = 0; j < m; j++)
      for (int i = 0; i < n; i++)
        if (grid[i][j])
          y.push_back(j);

    int ans = 0;
    int n1 = x.size();
    for (int i = 0; i < n1; i++)
      ans += abs(x[i] - x[n1 / 2]);

    int n2 = y.size();
    for (int i = 0; i < n2; i++)
      ans += abs(y[i] - y[n2 / 2]);

    return ans;
  }
};
