class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int ans = 0;
    int empty = 0;
    do {
      ans += numBottles;
      empty += numBottles;
      numBottles = empty / numExchange;
      empty %= numExchange;
      if (!numBottles)
        break;
    } while (true);
    return ans;
  }
};
