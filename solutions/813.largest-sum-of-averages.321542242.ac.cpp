class Solution {
public:
  double largestSumOfAverages(vector<int> &A, int K) {
    int n = A.size();

    for (int i = 1; i < n; i++)
      A[i] += A[i - 1];

    auto average = [&](int l, int r) {
      return (A[r] - (l == 0 ? 0 : A[l - 1])) / (r - l + 1.0);
    };

    vector<double> dp(n);

    for (int i = 0; i < n; i++)
      dp[i] = average(i, n - 1);

    for (int k = 1; k < K; k++) {
      for (int i = 0; i < n; i++)
        for (int j = i; j < n - 1; j++)
          dp[i] = max(dp[i], average(i, j) + dp[j + 1]);
    }

    return dp[0];
  }
};
