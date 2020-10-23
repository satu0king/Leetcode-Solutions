class Solution {
public:
  int minDistance(int height, int width, vector<int> &tree,
                  vector<int> &squirrel, vector<vector<int>> &nuts) {
    int ans = 0;
    int mx = INT_MIN;
    for (auto &p : nuts) {
      ans += 2 * dist(p, tree);
      mx = max(mx, dist(p, tree) - dist(p, squirrel));
    }
    return ans - mx;
  }

  int dist(vector<int> &p1, vector<int> &p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }
};
