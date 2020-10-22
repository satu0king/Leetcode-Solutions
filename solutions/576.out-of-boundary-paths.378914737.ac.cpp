long long const int p = 1e9 + 7;
class Solution {

  unordered_map<int, int> dp;

public:
  int findPaths(int &m, int &n, int N, int i, int j) {

    if (i < 0 || j < 0 || i >= m || j >= n)
      return 1;

    if (!N)
      return 0;

    int hash = h(i, j, N);
    if (dp.count(hash))
      return dp[hash];

    dp[hash] =
        ((findPaths(m, n, N - 1, i - 1, j) + findPaths(m, n, N - 1, i, j - 1)) %
             p +
         (findPaths(m, n, N - 1, i + 1, j) + findPaths(m, n, N - 1, i, j + 1)) %
             p) %
        p;

    return dp[hash];
  }

  int h(int i, int j, int N) { return i * 100 * 100 + j * 100 + N; }
};
