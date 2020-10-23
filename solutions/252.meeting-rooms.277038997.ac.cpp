class Solution {
public:
  bool canAttendMeetings(vector<vector<int>> &intervals) {
    return minMeetingRooms(intervals) <= 1;
  }

  int minMeetingRooms(vector<vector<int>> &intervals) {
    vector<vector<int>> events;

    for (auto interval : intervals) {
      events.push_back({interval[0], 1});
      events.push_back({interval[1], 0});
    }
    sort(events.begin(), events.end());
    int ans = 0;
    int current = 0;

    for (auto event : events) {
      if (!event[1])
        current--;
      else
        current++;
      ans = max(ans, current);
    }
    return ans;
  }
};
