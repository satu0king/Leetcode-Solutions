class Solution {
public:
  bool PredictTheWinner(vector<int> &nums) {
    return stoneGame(nums);
    int n = nums.size();

    vector<int> dp(n);

    for (int i = 0; i < n; i++)
      dp[i] = nums[i];

    for (int d = 1; d < n; d++)
      for (int i = 0; i < n - d; i++)
        dp[i] = max(nums[i] - dp[i + 1], nums[i + d] - dp[i]);

    return dp[0] >= 0;
  }
  bool stoneGame(vector<int> &piles) {

    int n = piles.size();

    vector<int> dp = piles;

    for (int d = 1; d < n; d++) {
      vector<int> dp_next(n);
      for (int i = 0; i + d < n; i++) {
        dp_next[i] = max(piles[i] - dp[i + 1], piles[i + d] - dp[i]);
      }
      dp = move(dp_next);
    }

    return dp[0] >= 0;
  }
};
