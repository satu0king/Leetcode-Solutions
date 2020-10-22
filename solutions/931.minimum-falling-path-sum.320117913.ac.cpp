class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &A) {
    int n = A.size();
    for (int i = 1; i < n; i++)
      for (int j = 0; j < n; j++) {
        int mn = A[i - 1][j];

        if (j)
          mn = min(A[i - 1][j - 1], mn);
        if (j < n - 1)
          mn = min(A[i - 1][j + 1], mn);

        A[i][j] += mn;
      }

    return *min_element(A[n - 1].begin(), A[n - 1].end());
  }
};
