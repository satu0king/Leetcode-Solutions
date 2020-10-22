class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == -2147483648 && divisor == -1)
      return 2147483647;
    int lol = (divisor < 0);
    divisor = abs(divisor);
    lol ^= (dividend < 0);
    dividend = abs(dividend);
    int lol2 = 1;
    if (lol)
      lol2 = -1;

    vector<long long> vals;
    vals.push_back(divisor);
    for (int i = 1; i < 32; i++) {
      long long nxt = vals.back() + vals.back();
      vals.push_back(nxt);
    }
    long long ans = 0;
    long long current = dividend;
    for (int i = 31; i >= 0; i--) {
      if (current - vals[i] >= 0) {
        current -= vals[i];
        ans += (1LL << i);
      }
    }
    cout << lol2 << " " << ans << endl;
    return 1LL * lol2 * ans;
  }
};
