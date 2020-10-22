class Solution {
public:
  int getSum(int a, int b) {
    while (a & b) {
      int t = a & b;
      a = a ^ b;
      b = (unsigned int)t << 1;
    }
    return a | b;
  }
};
