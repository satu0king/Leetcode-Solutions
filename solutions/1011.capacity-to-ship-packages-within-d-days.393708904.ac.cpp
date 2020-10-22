class Solution {

  bool canShip(vector<int> &weights, int D, int capacity) {
    int dayCount = 0;
    int remainingCapacity = 0;
    for (int w : weights) {
      if (w > remainingCapacity) {
        dayCount++;
        remainingCapacity = capacity;
      }
      remainingCapacity -= w;
    }
    return dayCount <= D;
  }

public:
  int shipWithinDays(vector<int> &weights, int d) {
    int start = *max_element(weights.begin(), weights.end());
    int s = accumulate(weights.begin(), weights.end(), 0);
    start = max(start, (s + d - 1) / d);
    while (!canShip(weights, d, start))
      start++;
    return start;
  }
};
