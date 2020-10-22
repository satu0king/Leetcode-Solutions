class Solution {
public:
  int minDeletionSize(vector<string> &A) {
    int ans = 0;
    int n = A.size();
    int w = A[0].size();
    vector<bool> satisfied(w);
    for (int j = 0; j < w; j++) {
      bool isDeleted = false;
      for (int i = 1; i < n; i++) {
        if (!satisfied[i] && A[i][j] < A[i - 1][j]) {
          ans++;
          isDeleted = true;
          break;
        }
      }
      if (!isDeleted) {
        for (int i = 1; i < n; i++)
          if (A[i][j] > A[i - 1][j])
            satisfied[i] = true;
      }
    }
    return ans;
  }
};
