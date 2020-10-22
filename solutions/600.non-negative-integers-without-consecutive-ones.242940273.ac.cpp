class Solution {
public:
  int findIntegers(int num) {
    if (num == 0)
      return 0;

    vector<int> dp(32);

    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < 32; i++)
      dp[i] = dp[i - 1] + dp[i - 2];

    int ans = 1;

    for (int i = 30; i >= 0; i--) {

      int currentBit = num & (1 << i);
      int prevBit = num & (1 << (i + 1));

      if (currentBit)
        ans += dp[i];

      if (currentBit && prevBit) {
        ans--;
        break;
      }
    }

    return ans;
  }
};
