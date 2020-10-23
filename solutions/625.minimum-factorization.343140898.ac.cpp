class Solution {
public:
  int smallestFactorization(int a) {
    if (a < 2)
      return a;
    long ans = 0, mul = 1;
    for (int i = 9; i >= 2; i--) {
      while (a % i == 0) {
        a /= i;
        ans = mul * i + ans;
        mul *= 10;
      }
    }
    return a < 2 and ans <= INT_MAX ? ans : 0;
  }
};
