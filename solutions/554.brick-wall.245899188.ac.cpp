class Solution {
public:
  int leastBricks(vector<vector<int>> &wall) {

    unordered_map<int, int> count;

    int n = wall.size();
    if (!n)
      return 0;

    for (int i = 0; i < n; i++) {
      int sm = 0;
      for (int j = 0; j < wall[i].size() - 1; j++) {
        sm += wall[i][j];
        count[sm]++;
      }
    }

    int mx = 0;
    for (auto p : count)
      mx = max(mx, p.second);
    return n - mx;
  }
};
