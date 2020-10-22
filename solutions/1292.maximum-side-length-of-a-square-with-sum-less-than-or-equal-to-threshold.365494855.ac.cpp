class Solution {
public:
  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    int n = mat.size();
    int m = mat[0].size();
    int ans = 0;
    int l = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (i)
          mat[i][j] += mat[i - 1][j];
        if (j)
          mat[i][j] += mat[i][j - 1];
        if (i && j)
          mat[i][j] -= mat[i - 1][j - 1];
        if (i + 1 >= l && j + 1 >= l) {
          int s = mat[i][j];
          if (i - l >= 0)
            s -= mat[i - l][j];
          if (j - l >= 0)
            s -= mat[i][j - l];
          if (j - l >= 0 && i - l >= 0)
            s += mat[i - l][j - l];
          if (s <= threshold)
            ans = l++;
        }
      }
    return ans;
  }
};
