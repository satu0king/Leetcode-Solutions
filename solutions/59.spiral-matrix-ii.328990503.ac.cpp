class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int rowStart = 0;
    int colStart = 0;
    int colEnd = n - 1;
    int rowEnd = n - 1;
    int k = 1;
    while (k <= n * n) {

      for (int j = colStart; j <= colEnd; j++)
        ans[rowStart][j] = k++;
      rowStart++;

      for (int i = rowStart; i <= rowEnd; i++)
        ans[i][colEnd] = k++;
      colEnd--;

      for (int j = colEnd; j >= colStart; j--)
        ans[rowEnd][j] = k++;
      rowEnd--;

      for (int i = rowEnd; i >= rowStart; i--)
        ans[i][colStart] = k++;
      colStart++;
    }

    return ans;
  }
};
