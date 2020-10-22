class Solution {
public:
  int numOfWays(int n) {
    const int mod = 1e9 + 7;

    long long int a121 = 6;
    long long int a123 = 6;
    long long int b121, b123;
    while (--n) {
      b121 = (3 * a121) % mod + (2 * a123) % mod;
      b123 = (2 * a121) % mod + (2 * a123) % mod;
      a121 = b121 % mod;
      a123 = b123 % mod;
    }
    return (a121 + a123) % mod;
  }
};
