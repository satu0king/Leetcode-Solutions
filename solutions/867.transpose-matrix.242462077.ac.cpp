class Solution {
public:
  vector<vector<int>> transpose(vector<vector<int>> &A) {
    int n = A.size();
    if (!n)
      return A;
    int m = A[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        ans[j][i] = A[i][j];

    return ans;
  }

  void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
  }
};
