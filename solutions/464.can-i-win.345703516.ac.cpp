class Solution {
public:
  bool canIWin(int n, int desiredSum) {
    // if A is playing, returns true if A can win in any turn
    // if B is playing, returns true if A has to win in every choice

    if (n * (n + 1) / 2 < desiredSum)
      return false;

    vector<char> dp(1 << n);
    return canAwin_util(dp, 0, desiredSum, n);
  }

  bool canAwin_util(vector<char> &dp, int state, int remainingSum, int n) {

    if (dp[state])
      return dp[state] > 0;

    for (int i = 0; i < n; i++) {
      if ((state & (1 << i)) == 0) {
        if (i + 1 >= remainingSum)
          return dp[state] = 1;

        bool ret = canAwin_util(dp, state | (1 << i), remainingSum - i - 1, n);
        if (!ret)
          return dp[state] = 1;
      }
    }

    dp[state] = -1;

    return false;
  }
};
