class Solution {
public:
  uint32_t reverseBits(uint32_t n) {

    for (int i = 0; i < 16; i++) {
      int j = 31 - i;
      int ai = n & (1 << i);
      int aj = n & (1 << j);
      if (ai)
        n |= (1 << j);
      else
        n &= ~(1 << j);
      if (aj)
        n |= (1 << i);
      else
        n &= ~(1 << i);
    }
    return n;
  }
};
