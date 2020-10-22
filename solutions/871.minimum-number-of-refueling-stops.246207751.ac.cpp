class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    int ans = 0;

    int currentPosition = 0;
    int n = stations.size();
    int i = 0;

    priority_queue<int> pq;
    int fuel = startFuel;

    while (currentPosition < target) {

      currentPosition += fuel;
      fuel = 0;
      if (currentPosition >= target)
        return ans;
      while (i < n && stations[i][0] <= currentPosition) {
        pq.push(stations[i][1]);
        i++;
      }

      if (pq.empty())
        return -1;
      else {
        fuel += pq.top();
        pq.pop();
        ans++;
      }
    }

    return ans;
  }
};
