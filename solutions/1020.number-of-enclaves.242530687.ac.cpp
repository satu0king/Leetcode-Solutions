class Solution {
public:
  int numEnclaves(vector<vector<int>> &A) {
    int n = A.size();
    if (!n)
      return 0;
    int m = A[0].size();

    int ans = 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        bool flag = true;
        int temp = dfs(A, i, j, flag);
        if (flag)
          ans += temp;
      }
    return ans;
  }

  int dfs(vector<vector<int>> &A, int i, int j, bool &flag) {
    int n = A.size();
    int m = A[0].size();
    if (i < 0 or i >= n)
      return 0;
    if (j < 0 or j >= m)
      return 0;
    if (!A[i][j])
      return 0;

    if (i + 1 == n or i == 0 or j + 1 == m or j == 0)
      flag = false;

    A[i][j] = 0;
    return dfs(A, i + 1, j, flag) + dfs(A, i - 1, j, flag) +
           dfs(A, i, j + 1, flag) + dfs(A, i, j - 1, flag) + 1;
  }
};
