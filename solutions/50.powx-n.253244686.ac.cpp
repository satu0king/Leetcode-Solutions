class Solution {
public:
  double myPow(double x, long long int n) {

    if (n == 0)
      return 1;
    bool sign = x < 0;
    if (n % 2 == 0)
      sign = false;
    x = abs(x);
    double ans = 1;
    if (n < 0) {
      x = 1 / x;
      n = -n;
    }

    while (n > 1) {
      if (n % 2)
        ans *= x;
      x *= x;
      n /= 2;
    }

    return sign ? -1 * ans * x : ans * x;
  }
};
