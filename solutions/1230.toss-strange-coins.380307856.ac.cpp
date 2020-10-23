class Solution {
public:
  double probabilityOfHeads(vector<double> &prob, int target) {
    vector<double> dp(target + 1);
    dp[0] = 1;

    for (auto p : prob) {
      for (int i = target; i >= 1; i--) {
        dp[i] = p * dp[i - 1] + (1 - p) * dp[i];
      }
      dp[0] *= 1 - p;
    }
    return dp[target];
  }
};
