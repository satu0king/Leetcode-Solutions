class Solution {
public:
  int arr[300][300];
  int func(int tli, int tlj, int i, int j) {
    int ans = arr[i][j];
    if (tlj - 1 >= 0)
      ans -= arr[i][tlj - 1];
    if (tli - 1 >= 0)
      ans -= arr[tli - 1][j];
    if (tli - 1 >= 0 and tlj - 1 >= 0)
      ans += arr[tli - 1][tlj - 1];
    return ans;
  }
  int countSquares(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int ans = 0;
    if (n == 0)
      return 0;
    int m = matrix[0].size();
    if (m == 0)
      return 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0)
          arr[i][j] = 0;
        else {
          if (i - 1 >= 0 and j - 1 >= 0)
            arr[i][j] =
                min(arr[i][j - 1], min(arr[i - 1][j], arr[i - 1][j - 1])) + 1;
          else
            arr[i][j] = 1;
          ans += arr[i][j];
        }
      }
    }
    return ans;
  }
};
