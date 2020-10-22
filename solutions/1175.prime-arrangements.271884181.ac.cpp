class Solution {
  int p;

public:
  int numPrimeArrangements(int n) {
    p = 1e9 + 7;
    vector<bool> prime(101, 1);
    prime[1] = false;
    int c = 0;
    for (int i = 2; i <= n; i++) {
      if (prime[i]) {
        for (int j = 2 * i; j <= n; j += i)
          prime[j] = false;
        c++;
      }
    }

    long long int ans = fact(c);
    ans *= fact(n - c);
    return ans % p;
  }

  long long int fact(int n) {
    long long int ans = 1;
    for (int i = 1; i <= n; i++) {
      ans *= i;
      ans %= p;
    }
    return ans;
  }
};
