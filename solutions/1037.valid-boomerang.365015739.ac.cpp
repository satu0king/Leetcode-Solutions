class Solution {
public:
  bool isBoomerang(vector<vector<int>> &points) {
    int dy1 = points[0][1] - points[1][1];
    int dx1 = points[0][0] - points[1][0];
    int dy2 = points[2][1] - points[1][1];
    int dx2 = points[2][0] - points[1][0];
    if (dx1 == 0 && dy1 == 0)
      return false;
    if (dx2 == 0 && dy2 == 0)
      return false;
    if (points[0] == points[2])
      return false;

    if (dx1 == 0 || dx2 == 0) {
      return dx1 != dx2;
    }

    return dy1 * dx2 != dy2 * dx1;
  }
};
