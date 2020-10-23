class Solution {
public:
  double minmaxGasDist(vector<int> &stations, int K) {
    int n = stations.size();
    double l = 0, r = stations[n - 1] - stations[0];
    double ans = 0;
    while (l + 1e-6 < r) {
      double mid = (l + r) / 2.0;
      int count = 0;
      for (int i = 0; i < n - 1; ++i)
        count += ceil((stations[i + 1] - stations[i]) / mid) - 1;
      if (count > K) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return r;
  }
};
