class Solution {
public:
  int consecutiveNumbersSum(int N) {
    int sq = sqrt(2 * N + 1);
    int ans = 0;
    for (int i = 1; i <= sq; i++) {
      if ((N - i * (i + 1) / 2) % i == 0)
        ans++;
    }
    return ans;
  }
};
