class Solution {
public:
  int maximumMinimumPath(vector<vector<int>> &A) {
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    priority_queue<tuple<int, int, int>> q;
    q.emplace(A[0][0], 0, 0);
    int m = A.size(), n = A[0].size(), maxscore = A[0][0];
    A[0][0] = -1; // visited

    while (!q.empty()) {
      auto [a, i, j] = q.top();
      q.pop();
      maxscore = min(maxscore, a);
      if (i == m - 1 && j == n - 1)
        break;

      for (auto &d : dir) {
        int x = i + d.first;
        int y = j + d.second;

        if (x >= 0 and x < m and y >= 0 and y < n and A[x][y] >= 0) {
          q.emplace(A[x][y], x, y);
          A[x][y] = -1;
        }
      }
    }
    return maxscore;
  }
};
