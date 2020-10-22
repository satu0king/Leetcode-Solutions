class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
    int n = M.size();
    int m = M[0].size();
    vector<vector<int>> ans(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int c = 0;
        int s = 0;

        for (int ii = i - 1; ii <= i + 1; ii++)
          for (int jj = j - 1; jj <= j + 1; jj++)
            if (ii >= 0 && jj >= 0 && ii < n && jj < m) {
              c++;
              s += M[ii][jj];
            }

        ans[i][j] = s / c;
      }
    }

    return ans;
  }
};
