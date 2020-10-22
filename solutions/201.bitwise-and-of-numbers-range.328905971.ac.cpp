class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    int ans = 0;
    for (int bit = 31; bit >= 0; bit--) {
      int b1 = m & (1 << bit);
      int b2 = n & (1 << bit);
      if (b1 ^ b2)
        break;
      if (b1)
        ans += 1 << bit;
    }
    return ans;
  }
};
