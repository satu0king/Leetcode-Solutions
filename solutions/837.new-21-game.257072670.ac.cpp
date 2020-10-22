
class Solution {
public:
  double new21Game(int N, int K, int W) {
    vector<double> dp(K + W);

    for (int i = K; i <= min(K + W - 1, N); i++)
      dp[i] = 1;

    double s = min(N - (K - 1), W);

    for (int j = K - 1; j >= 0; j--) {
      dp[j] = s / W;
      s += dp[j] - dp[j + W];
    }

    return dp[0];
  }
};
