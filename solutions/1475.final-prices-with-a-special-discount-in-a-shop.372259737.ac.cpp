class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    stack<int> s;
    int n = prices.size();
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
      ans[i] = prices[i];
      while (s.size() && s.top() > prices[i])
        s.pop();
      if (s.size())
        ans[i] -= s.top();
      s.push(prices[i]);
    }
    return ans;
  }
};
