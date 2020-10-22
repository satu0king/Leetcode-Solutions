/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
  vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
    vector<vector<int>> ans;
    int l = 1;
    int r = 1000;
    while (l <= 1000 && r >= 1) {
      int v = customfunction.f(l, r);
      if (v == z) {
        ans.push_back({l, r});
        l++;
      } else if (v > z) {
        r--;
      } else {
        l++;
      }
    }
    return ans;
  }
};
