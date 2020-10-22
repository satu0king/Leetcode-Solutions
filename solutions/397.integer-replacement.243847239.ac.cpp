class Solution {
public:
  long long int integerReplacement(long long int n) {
    if (n == 1)
      return 0;
    if (n % 2)
      return min(integerReplacement(n - 1), integerReplacement(n + 1)) + 1;
    return integerReplacement(n / 2) + 1;
  }
};
