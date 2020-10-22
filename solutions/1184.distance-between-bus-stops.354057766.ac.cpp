class Solution {
public:
  int distanceBetweenBusStops(vector<int> &distance, int start,
                              int destination) {
    int ans = 0;
    int t = start;
    while (t != destination) {
      ans += distance[t++];
      t %= distance.size();
    }
    int temp = 0;
    t = destination;
    while (t != start) {
      temp += distance[t++];
      t %= distance.size();
    }
    return min(ans, temp);
  }
};
