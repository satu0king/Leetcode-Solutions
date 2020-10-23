class Solution {
public:
  vector<vector<int>> removeInterval(vector<vector<int>> &intervals,
                                     vector<int> &toBeRemoved) {
    vector<vector<int>> ans;

    for (auto &interval : intervals) {
      int r = min(interval[1], toBeRemoved[1]);
      int l = max(interval[0], toBeRemoved[0]);
      if (l >= r) {
        ans.push_back(interval);
      } else {
        if (l > interval[0])
          ans.push_back({interval[0], l});
        if (r < interval[1])
          ans.push_back({r, interval[1]});
      }
    }

    return ans;
  }
};
