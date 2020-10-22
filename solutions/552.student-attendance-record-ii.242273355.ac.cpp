class Solution {
public:
  int checkRecord(int n) {
    // 0 - no absent
    // 1 - no absent and ending with late
    // 2 - one absent
    // 3 - one absent and ending with late
    vector<vector<long long int>> dp(n + 1, vector<long long int>(4));

    long long int p = 10e8 + 7;

    dp[1][0] = 1; // 'P'
    dp[1][1] = 1; // 'L'
    dp[1][2] = 1; // 'A'
    dp[1][3] = 0; // Not possible

    dp[0][0] = 1; // seeded so that DP works

    for (int i = 2; i <= n; i++) {
      dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) %
                 p; // (present yesterday or late yesterday) and present today
      dp[i][1] = (dp[i - 1][0] + dp[i - 2][0]) %
                 p; // (present yesterday and late today) or (present 2 days
                    // back and late for 2 days)
      dp[i][2] =
          (dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][0] + dp[i - 1][1]) % p;
      // ((present yesterday with one absent or late yesterday with one absent)
      // and present today) or ((present yesterday with no absent or late
      // yesterday with no absent) and absent today )
      dp[i][3] = (dp[i - 1][2] + dp[i - 2][2]) % p;
      // (present yesterday and late today with one absent) or (present 2 days
      // back and late for 2 days with one absent)
    }

    return (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3]) % p;
  }
};
