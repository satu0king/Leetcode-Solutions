class Solution {
public:
  int minDominoRotations(vector<int> &A, vector<int> &B) {
    int ans = -1;

    int n = A.size();

    for (int j = 1; j <= 6; j++) {
      int tempA = 0;
      int tempB = 0;
      for (int i = 0; i < n; i++) {
        if (A[i] == j && B[i] == j)
          continue;
        if (A[i] != j && B[i] != j) {
          tempA = -1;
          tempB = -1;
          break;
        }
        if (A[i] != j)
          tempA++;
        else
          tempB++;
      }
      if (~tempA)
        if (~ans)
          ans = min(ans, min(tempA, tempB));
        else
          ans = min(tempA, tempB);
    }
    return ans;
  }
};
