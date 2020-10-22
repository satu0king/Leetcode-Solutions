class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {

    int lastFleetSpeed = -1;
    int lastFleetPosition = -1;

    vector<pair<int, int>> v;

    int n = position.size();
    for (int i = 0; i < n; i++)
      v.emplace_back(position[i], speed[i]);

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int ans = 0;

    for (auto p : v) {
      int speed = p.second;
      int position = p.first;

      if (lastFleetPosition == -1 ||
          time(target, position, speed) >
              time(target, lastFleetPosition, lastFleetSpeed)) {
        lastFleetPosition = position;
        lastFleetSpeed = speed;
        ans++;
      }
    }

    return ans;
  }

  double time(int target, int position, int speed) {
    return (0.0 + target - position) / (double)speed;
  }
};
