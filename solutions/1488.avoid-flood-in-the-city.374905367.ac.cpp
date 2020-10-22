class Solution {
public:
  vector<int> avoidFlood(vector<int> &rains) {
    set<int> dryDays;
    unordered_map<int, int> wetLakes;
    int n = rains.size();
    vector<int> ans(n, 1);
    for (int i = 0; i < rains.size(); i++) {
      if (rains[i]) {
        int lake = rains[i];
        if (wetLakes.count(lake)) {
          auto it = dryDays.lower_bound(wetLakes[lake]);
          if (it == dryDays.end())
            return {};
          ans[*it] = lake;
          dryDays.erase(it);
        }
        wetLakes[lake] = i;
        ans[i] = -1;
      } else
        dryDays.insert(i);
    }
    return ans;
  }
};
