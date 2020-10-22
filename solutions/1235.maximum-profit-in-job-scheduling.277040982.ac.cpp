class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {

    vector<int> idx(startTime.size());
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx),
         [&](int i, int j) { return startTime[i] > startTime[j]; });
    map<int, int> memo;
    int max_profit = 0;
    for (auto i = 0; i < idx.size(); ++i) {
      auto it = memo.lower_bound(endTime[idx[i]]);
      max_profit =
          max(max_profit, (it == end(memo) ? 0 : it->second) + profit[idx[i]]);
      memo[startTime[idx[i]]] = max_profit;
    }
    return max_profit;
  }
};
