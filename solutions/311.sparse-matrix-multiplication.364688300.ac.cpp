class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
    unordered_map<int, unordered_set<int>> Bsparse;
    int n = A.size();
    int k = A[0].size();
    int m = B[0].size();

    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < k; j++)
        if (A[i][j]) {
          for (int t = 0; t < m; t++) {

            ans[i][t] += B[j][t] * A[i][j];
          }
        }

    return ans;
  }
};
