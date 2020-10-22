class Solution {
public:
  int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B) {
    int ans = 0;
    int n1 = A.size();
    int n2 = B.size();

    for (int i = 0; i < n2; i++)
      for (int j = 0; j < n2; j++)
        ans = max(ans, f(A, B, i, j));

    for (int i = 0; i < n1; i++)
      for (int j = 0; j < n1; j++)
        ans = max(ans, f(B, A, i, j));

    return ans;
  }

  int f(vector<vector<int>> &A, vector<vector<int>> &B, int i, int j) {
    int n1 = A.size();
    int n2 = B.size();

    int count = 0;

    for (int i1 = 0, i2 = i; i1 < n1 && i2 < n2; i1++, i2++)
      for (int j1 = 0, j2 = j; j1 < n1 && j2 < n2; j1++, j2++)
        count += A[i1][j1] & B[i2][j2];

    return count;
  }
};
