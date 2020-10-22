

class Solution {
public:
  int minCut(string A) {
    int n = A.size();
    vector<int> cuts(n + 1);
    for (int i = 0; i <= n; i++)
      cuts[i] = i - 1;

    for (int i = 0; i < n; i++) {
      // Odd
      for (int j = 0; i - j >= 0 && i + j < n && A[i - j] == A[i + j]; j++) {
        cuts[i + j + 1] = min(cuts[i + j + 1], cuts[i - j] + 1);
      }
      // Even
      for (int j = 0; i - j - 1 >= 0 && i + j < n && A[i - j - 1] == A[i + j];
           j++) {
        cuts[i + j + 1] = min(cuts[i + j + 1], cuts[i - j - 1] + 1);
      }
    }
    return cuts[n];
  }
};
