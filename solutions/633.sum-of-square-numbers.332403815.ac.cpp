class Solution {
public:
  bool judgeSquareSum(int c) {

    for (long i = 0; i * i <= c; i++) {
      int t = c - i * i;
      double sqt = sqrt(t);
      if (sqt == (int)sqt)
        return true;
    }

    return false;
  }
};
