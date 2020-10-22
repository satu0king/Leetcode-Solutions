

class Solution {
public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens,
                                          vector<int> &k) {
    bool b[8][8] = {};
    for (auto &q : queens)
      b[q[0]][q[1]] = true;
    vector<vector<int>> res;
    for (auto i = -1; i <= 1; ++i)
      for (auto j = -1; j <= 1; ++j) {
        if (i == 0 && j == 0)
          continue;
        auto x = k[0] + i, y = k[1] + j;
        while (min(x, y) >= 0 && max(x, y) < 8) {
          if (b[x][y]) {
            res.push_back({x, y});
            break;
          }
          x += i, y += j;
        }
      }
    return res;
  }
};
