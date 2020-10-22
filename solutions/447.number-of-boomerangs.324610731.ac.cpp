class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    int ans = 0;

    int n = points.size();
    for (int i = 0; i < n; i++) {
      unordered_map<int, int> mp;
      int x1 = points[i][0];
      int y1 = points[i][1];
      for (int j = 0; j < n; j++) {
        int x2 = points[j][0];
        int y2 = points[j][1];
        int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        ans += 2 * mp[d];
        mp[d]++;
      }
    }
    return ans;
  }
};
