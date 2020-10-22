const int P = 1e9 + 7;
class Solution {
public:
  int numTilings(int N) {
    vector<vector<long long int>> DP(N + 1, vector<long long int>(4));
    DP[0][0] = 1;
    for (int i = 1; i <= N; i++) {

      DP[i][0] += DP[i - 1][0];
      DP[i][0] += DP[i - 1][3];

      DP[i][1] += DP[i - 1][0];
      DP[i][1] += DP[i - 1][2];

      DP[i][2] += DP[i - 1][0];
      DP[i][2] += DP[i - 1][1];

      DP[i][3] += DP[i - 1][1];
      DP[i][3] += DP[i - 1][2];
      DP[i][3] += DP[i - 1][0];

      for (auto &j : DP[i])
        j %= P;
    }

    return DP[N][0];
  }
};

/*

P C

0 -> 1, 2, 0, 3
X *
X *

1 -> 2, 3
X X
X *

2 -> 1, 3
X *
X X

3 -> 0
X X
X X

*/
