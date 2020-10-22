class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {

    k = min(k, (int)prices.size() / 2);
    if (k == 0)
      return 0;

    vector<int> minCost(k, INT_MAX);
    vector<int> maxProfit(k);
    for (auto price : prices)
      for (int i = 0; i < k; i++) {
        int prevProfit = i ? maxProfit[i - 1] : 0;
        minCost[i] = min(minCost[i], price - prevProfit);
        maxProfit[i] = max(maxProfit[i], price - minCost[i]);
      }

    return maxProfit[k - 1];
  }
};
