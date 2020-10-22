class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n - 1; i++)
      for (int j = 0; j < m - 1; j++)
        if (matrix[i + 1][j + 1] != matrix[i][j])
          return false;
    return true;
  }
};
