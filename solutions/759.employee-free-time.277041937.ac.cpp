/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
  vector<Interval *> employeeFreeTime(vector<vector<Interval *>> schedule) {
    map<int, int> workTimes;
    for (auto emp : schedule)
      for (auto interval : emp) {
        workTimes[interval->start]++;
        workTimes[interval->end]--;
      }

    int cumulative = 0;
    vector<Interval *> ans;
    int lastFree = -1;

    for (auto time : workTimes) {
      cumulative += time.second;
      time.second = cumulative;

      if (time.second == 0 && lastFree == -1)
        lastFree = time.first;

      if (~lastFree && time.second) {
        ans.push_back(new Interval(lastFree, time.first));
        lastFree = -1;
      }
    }

    return ans;
  }
};
