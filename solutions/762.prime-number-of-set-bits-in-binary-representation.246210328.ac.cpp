class Solution {
public:
  int countPrimeSetBits(int L, int R) {
    vector<char> dp(1000001);
    dp[1] = 1;

    for (int i = 2; i < dp.size(); i++)
      dp[i] = dp[i & (i - 1)] + 1;

    for (int i = 0; i < dp.size(); i++)
      dp[i] = isPrime(dp[i]);

    int ans = 0;
    for (int i = L; i <= R; i++)
      ans += dp[i];

    return ans;
  }

  bool isPrime(int n) {
    if (n == 1)
      return false;
    if (n == 2)
      return true;

    if (n % 2 == 0)
      return false;

    for (int i = 3; i * i <= n; i += 2)
      if (n % i == 0)
        return false;

    return true;
  }
};
