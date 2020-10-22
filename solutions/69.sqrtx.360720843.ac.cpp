class Solution {
public:
  int mySqrt(int x) {
    int l = 0;
    int r = x;
    int ans;
    while (l <= r) {
      long long m = (l + r) / 2;
      if (m * m <= x) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }
};

// Search space [0 - n] in array
// answer - something in search space
// if A is wrong, then either > A is wrong or < A is wrong
