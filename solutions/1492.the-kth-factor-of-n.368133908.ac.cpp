class Solution {
public:
  int kthFactor(int n, int k) {
    int d = 1;
    for (; d * d <= n; ++d)
      if (n % d == 0 && --k == 0)
        return d;
    for (d = d - 1; d >= 1; --d) {
      if (d * d == n)
        continue;
      if (n % d == 0 && --k == 0)
        return n / d;
    }
    return -1;
  }
};
