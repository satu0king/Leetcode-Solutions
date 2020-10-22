class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {

    int startx = points[0][0];
    int starty = points[0][1];

    int ans = 0;

    for (auto &p : points) {
      int x = abs(p[0] - startx);
      int y = abs(p[1] - starty);

      ans += max(x, y);
      startx = p[0];
      starty = p[1];
    }

    return ans;
  }
};
