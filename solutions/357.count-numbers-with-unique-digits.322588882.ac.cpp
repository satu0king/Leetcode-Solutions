class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {

    int ans = 1;

    for (int i = 1; i <= min(n, 10); i++) {

      int t = 9;
      for (int j = 1, c = 9; j < i; j++, c--) {
        t *= c;
      }

      ans += t;
    }

    return ans;
  }
};
