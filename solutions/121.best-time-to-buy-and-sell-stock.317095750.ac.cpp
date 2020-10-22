class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    int n = prices.size();

    if (!n)
      return 0;

    int mn = prices[0];

    for (int i = 1; i < n; i++) {
      mn = min(mn, prices[i]);
      ans = max(ans, prices[i] - mn);
    }
    return ans;
  }
};
