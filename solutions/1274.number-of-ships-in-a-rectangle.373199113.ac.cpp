/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
  int countShips(Sea &sea, vector<int> topRight, vector<int> bottomLeft) {
    int x1 = bottomLeft[0];
    int y1 = bottomLeft[1];
    int x2 = topRight[0];
    int y2 = topRight[1];
    if (x1 > x2 || y1 > y2)
      return 0;
    bool hasShips = sea.hasShips(topRight, bottomLeft);
    if (!hasShips)
      return 0;
    if (topRight == bottomLeft)
      return true;

    int mx = (x1 + x2) / 2;
    int my = (y1 + y2) / 2;
    int ans = 0;
    ans += countShips(sea, {x2, y2}, {mx + 1, my + 1});
    ans += countShips(sea, {mx, my}, {x1, y1});
    ans += countShips(sea, {mx, y2}, {x1, my + 1});
    ans += countShips(sea, {x2, my}, {mx + 1, y1});
    return ans;
  }
};
