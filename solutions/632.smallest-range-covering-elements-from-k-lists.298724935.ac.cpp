class Solution {

  int leftBest;
  int rightBest;

public:
  vector<int> smallestRange(vector<vector<int>> &nums) {

    vector<vector<int>> events;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < nums[i].size(); j++) {
        events.push_back({nums[i][j], i});
      }
    }
    sort(events.begin(), events.end());

    int c = 0;

    int l = 0;
    vector<int> ans = {events[0][0], events.back()[0]};
    int smallest = ans[1] - ans[0];
    unordered_map<int, int> mp;
    for (int r = 0; r < events.size(); r++) {

      if (mp[events[r][1]] == 0)
        c++;

      mp[events[r][1]]++;

      while (mp[events[l][1]] > 1) {
        mp[events[l++][1]]--;
      }

      if (c == n && events[r][0] - events[l][0] < smallest) {
        ans = {events[l][0], events[r][0]};
        smallest = events[r][0] - events[l][0];
      }
    }

    return ans;
  }
};
