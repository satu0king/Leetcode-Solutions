class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (!n)
      return 0;
    vector<int> maxProfit(n);
    int maxHold = INT_MIN;

    for (int i = 0; i < n; i++) {
      int p = prices[i];

      maxProfit[i] = max(i ? maxProfit[i - 1] : 0, maxHold + p);
      maxHold = max((i - 2 >= 0 ? maxProfit[i - 2] : 0) - p, maxHold);
    }

    return maxProfit[n - 1];
  }
};
