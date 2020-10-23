class Solution {
public:
  int minKnightMoves(int x, int y) {

    int ans = 0;
    std::unordered_map<int, std::unordered_map<int, bool>> visited;
    std::vector<std::vector<int>> directions = {
        {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    visited[0][0] = true;

    int d = max(x * x + y * y, 5);

    while (q.size()) {
      int n = q.size();

      // cout << ans <<" " << n << endl;

      while (n--) {
        auto p = q.front();
        q.pop();

        int x1 = p.first;
        int y1 = p.second;

        // cout << x1 <<" " << y1 << endl;

        if (x1 == x && y1 == y)
          return ans;

        for (auto &dir : directions) {
          int x2 = x1 + dir[0];
          int y2 = y1 + dir[1];
          int new_d = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);

          if (!visited[x2][y2] && new_d <= d) {
            visited[x2][y2] = true;
            q.emplace(x2, y2);

            d = max(min(new_d, d), 5);
          }
        }
      }
      ans++;
      // cout << ans << " " << d_x << " " << q.size() << endl;
    }

    return -1;
  }
};
