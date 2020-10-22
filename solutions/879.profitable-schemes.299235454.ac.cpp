
const int MOD = 1e9 + 7;

class Solution {
public:
  int profitableSchemes(int G, int P, vector<int> &group, vector<int> &profit) {

    vector<vector<int>> dp(P + 1, vector<int>(G + 1));
    dp[0][0] = 1;

    for (int i = 0; i < profit.size(); i++) {

      auto dp_next = dp;
      int p = profit[i];
      int g = group[i];

      for (int j = P; j >= 0; j--) {
        int newP = min(p + j, P);
        for (int k = G - g; k >= 0; k--) {
          dp_next[newP][k + g] += dp[j][k];
          dp_next[newP][k + g] %= MOD;
        }
      }
      swap(dp_next, dp);
    }

    int ans = 0;
    for (int i = 0; i <= G; i++) {
      ans += dp[P][i];
      ans %= MOD;
    }
    return ans;
  }
};
