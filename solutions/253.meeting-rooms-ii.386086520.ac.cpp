class Solution {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    multiset<pair<int, int>> s;
    int ans = 0;
    for (auto &e : intervals) {
      int start = e[0];
      int end = e[1];
      if (s.size() == 0)
        s.insert({end, start});
      else {
        auto itr = *s.begin();
        if (itr.first <= start) {
          s.erase(s.begin());
          s.insert({end, start});
        } else {
          s.insert({end, start});
        }
      }
      ans = max(ans, (int)s.size());
    }
    return ans;
  }
};
