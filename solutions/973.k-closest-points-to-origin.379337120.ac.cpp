class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
    nth_element(points.begin(), points.begin() + K, points.end(),
                [](vector<int> &p, vector<int> &q) {
                  return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
                });
    return vector<vector<int>>(points.begin(), points.begin() + K);
  }

  static bool f(vector<int> p1, vector<int> p2) {
    return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
  }
};
