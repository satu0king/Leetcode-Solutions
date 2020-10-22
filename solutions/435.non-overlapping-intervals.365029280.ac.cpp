class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int ans = 0;
    sort(intervals.begin(), intervals.end());
    int endingIndex = INT_MIN;
    for (auto interval : intervals) {
      if (interval[0] >= endingIndex) {
        endingIndex = interval[1];
      } else {
        ans++;
        endingIndex = min(interval[1], endingIndex);
      }
    }
    return ans;
  }
};
