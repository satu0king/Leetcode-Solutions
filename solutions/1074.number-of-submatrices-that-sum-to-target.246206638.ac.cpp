class Solution {
  vector<vector<int>> matrix;

public:
  int numSubmatrixSumTarget(vector<vector<int>> &_matrix, int target) {
    matrix = _matrix;
    // _matrix.clear();
    int n = matrix.size();
    if (!n)
      return 0;
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        matrix[i][j] += id(i - 1, j) + id(i, j - 1) - id(i - 1, j - 1);

    int ans = 0;

    // cout<<"HIT"<<endl;

    for (int x1 = -1; x1 < m; x1++)
      for (int x2 = x1 + 1; x2 < m; x2++) {
        unordered_map<int, int> count;
        for (int y = -1; y < n; y++) {
          ans += count[A(x2, y) - A(x1, y)];
          count[target - A(x1, y) + A(x2, y)]++;
        }
      }

    return ans;
  }

  long long int id(int i, int j) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (i < 0 or j < 0 or i >= n or j >= m)
      return 0;
    return matrix[i][j];
  }
  long long int A(int j, int i) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (i < 0 or j < 0 or i >= n or j >= m)
      return 0;
    return matrix[i][j];
  }
};
