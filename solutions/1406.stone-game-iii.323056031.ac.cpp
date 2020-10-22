static auto io_accelerator = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    int n = stoneValue.size();
    for (int i = n - 2; i >= 0; i--)
      stoneValue[i] += stoneValue[i + 1];

    //         auto f = [&stoneValue](int i) {
    //             if(i)
    //                 return   stoneValue[i] - stoneValue[i-1];
    //             return stoneValue[i];
    //         };

    vector<int> dp(n + 1, INT_MIN);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
      for (int x = 1; x <= 3 && i + x <= n; x++)
        dp[i] = max(dp[i], stoneValue[i] - dp[i + x]);
    }

    int aliceScore = dp[0];
    int bobScore = stoneValue[0] - aliceScore;

    if (aliceScore > bobScore)
      return "Alice";
    else if (aliceScore < bobScore)
      return "Bob";
    else
      return "Tie";
  }
};
