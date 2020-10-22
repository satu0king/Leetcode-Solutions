class Solution {
public:
  int largestValsFromLabels(vector<int> &values, vector<int> &labels,
                            int num_wanted, int use_limit) {
    multimap<int, int> map;
    unordered_map<int, int> used;
    for (int i = 0; i < values.size(); i++)
      map.emplace(values[i], labels[i]);
    int ans = 0;
    for (auto i = map.rbegin(); i != map.rend() && num_wanted; i++)
      if (used[i->second]++ < use_limit) {
        ans += i->first;
        num_wanted--;
      }

    return ans;
  }
};
