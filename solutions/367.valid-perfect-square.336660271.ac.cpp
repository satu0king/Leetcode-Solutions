class Solution {
public:
  bool isPerfectSquare(int num) {
    int sq = sqrt(num);
    return sq * sq == num;
  }
};
