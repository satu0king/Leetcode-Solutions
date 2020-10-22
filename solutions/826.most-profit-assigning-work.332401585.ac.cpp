class Solution {
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {
    vector<pair<int, int>> a;
    for (int i = 0; i < difficulty.size(); i++)
      a.emplace_back(difficulty[i], profit[i]);

    sort(a.begin(), a.end());
    sort(worker.begin(), worker.end());

    int mxProfit = 0;
    int ans = 0;

    int i = 0;

    for (int w : worker) {
      while (i < a.size() && a[i].first <= w) {
        mxProfit = max(mxProfit, a[i++].second);
      }
      ans += mxProfit;
    }

    return ans;
  }
};
