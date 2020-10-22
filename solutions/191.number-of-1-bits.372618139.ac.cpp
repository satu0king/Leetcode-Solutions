class Solution {
public:
  int hammingWeight(uint32_t n) {
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
      uint32_t x = (1 << i);
      if (n & x)
        cnt++;
    }
    return cnt;
  }
};
