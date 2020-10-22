class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int maxProfit = 0;
    int maxHolding = INT_MIN;

    for (int p : prices) {
      maxHolding = max(maxHolding, maxProfit - fee - p);
      maxProfit = max(maxHolding + p, maxProfit);
    }

    return maxProfit;
  }
};
