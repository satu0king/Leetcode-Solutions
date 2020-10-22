class Solution {
public:
  int maxStudents(vector<vector<char>> &seats) {

    int n = seats[0].size();
    int m = 1 << n;

    vector<pair<int, int>> dp = {{0, 0}};
    vector<pair<int, int>> dp_next;

    for (auto &row : seats) {
      dp_next.clear();

      for (int mask = m - 1; mask >= 0; mask--) {

        bool flag = true;
        for (int i = 0; i < n && flag; i++)
          if (row[i] == '#' && (mask & (1 << i)))
            flag = false;

        if (!flag)
          continue;

        for (int i = 2; i < m && flag; i = i << 1)
          if ((mask & i) && (mask & (i >> 1)))
            flag = false;

        if (!flag)
          continue;

        int c = __builtin_popcount(mask);

        int bestScore = 0;

        for (auto [mask2, score] : dp) {
          if (bestScore >= score)
            continue;
          bool flag = true;

          for (int i = 2; i < m && flag; i = i << 1) {
            if ((mask & i) && (mask2 & (i / 2)))
              flag = false;
            if ((mask2 & i) && (mask & (i / 2)))
              flag = false;
          }

          if (!flag)
            continue;

          bestScore = score;
        }

        dp_next.emplace_back(mask, bestScore + c);
      }

      swap(dp, dp_next);
    }

    int ans = 0;
    for (auto [_, s] : dp)
      ans = max(ans, s);

    return ans;
  }
};
