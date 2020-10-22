bool cmp(vector<int> &v1, vector<int> &v2) {
  if (v1[0] != v2[0])
    return v1[0] < v2[0];
  return v1[1] > v2[1];
}

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    int r = -1;
    int ans = intervals.size();
    for (auto &interval : intervals)
      if (interval[1] <= r)
        ans--;
      else
        r = max(r, interval[1]);

    return ans;
  }
};
