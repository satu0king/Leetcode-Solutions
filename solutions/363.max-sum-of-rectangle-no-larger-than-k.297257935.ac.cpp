class Solution {

  int f(vector<int> &v, int k) {

    for (int k = 1; k < v.size(); k++)
      v[k] += v[k - 1];

    set<int> s;
    s.insert(0);
    int ans = INT_MIN;
    for (int c : v) {

      auto j = s.lower_bound(c - k);

      if (j != s.end())
        ans = max(ans, c - *j);

      s.insert(c);
    }

    return ans;
  }

public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (n < m)
      return f1(matrix, k);
    vector<vector<int>> matrix1(m, vector<int>(n));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        matrix1[j][i] = matrix[i][j];

    return f1(matrix1, k);
  }
  int f1(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = INT_MIN;
    for (int i = 1; i < n; i++)
      for (int j = 0; j < m; j++)
        matrix[i][j] += matrix[i - 1][j];

    // for(int i = 0; i < n; i++)
    //     ans = min(ans, *min_element(matrix[i].begin(), matrix[i].end()));

    for (int i = 0; i < n; i++)
      for (int j = i; j < n; j++) {
        vector<int> v(m);
        for (int k = 0; k < m; k++)
          v[k] = matrix[j][k] - (i ? matrix[i - 1][k] : 0);

        ans = max(ans, f(v, k));
      }

    return ans;
  }
};
