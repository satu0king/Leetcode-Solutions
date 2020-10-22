class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int n = grid.size();
    if (!n)
      return 0;
    int m = grid[0].size();

    int i = 0;
    int j = m - 1;

    int ans = 0;

    while (i < n && j >= 0) {
      if (grid[i][j] < 0) {
        ans += n - i;
        j--;
      } else
        i++;
    }

    return ans;
  }
};
