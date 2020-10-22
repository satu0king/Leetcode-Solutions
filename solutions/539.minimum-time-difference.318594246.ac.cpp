class Solution {
public:
  int findMinDifference(vector<string> &timePoints) {
    int totalMinutes = 60 * 24;

    vector<int> minutes;
    for (auto &s : timePoints) {
      int h = stoi(s.substr(0, 2));
      int m = stoi(s.substr(3));
      minutes.push_back(h * 60 + m);
    }
    sort(minutes.begin(), minutes.end());

    int ans = minutes.front() - minutes.back() + totalMinutes;

    for (int i = 1; i < minutes.size(); i++)
      ans = min(ans, minutes[i] - minutes[i - 1]);
    return ans;
  }
};
