class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    int n = mat.size();
    if (!n)
      return mat;
    int m = mat[0].size();
    for (int i = 0; i < n; i++) {
      vector<int> temp;

      for (int k = 0; k < min(m, n - i); k++)
        temp.push_back(mat[i + k][k]);
      sort(temp.begin(), temp.end());

      for (int k = 0; k < min(m, n - i); k++)
        mat[i + k][k] = temp[k];
    }
    for (int j = 1; j < m; j++) {
      vector<int> temp;

      for (int k = 0; k < min(m - j, n); k++)
        temp.push_back(mat[k][j + k]);
      sort(temp.begin(), temp.end());

      for (int k = 0; k < min(m - j, n); k++)
        mat[k][j + k] = temp[k];
    }
    return mat;
  }
};
