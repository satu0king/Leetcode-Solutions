class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int bestHold1 = INT_MIN;
    int bestHold2 = INT_MIN;
    int bestSold1 = 0;
    int bestSold2 = 0;
    for (int a : prices) {
      bestHold2 = max(bestHold2, bestSold1 - a); // Buy a, second time
      bestHold1 = max(bestHold1, -a);            // Buy a first time
      bestSold2 = max(bestSold2, bestHold2 + a); // Sell a, second time
      bestSold1 = max(bestSold1, bestHold1 + a); // Sell a first time
    }
    return bestSold2;
  }
};
