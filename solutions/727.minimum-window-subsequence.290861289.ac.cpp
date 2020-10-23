class Solution {
public:
  string minWindow(string S, string T) {
    int n1 = S.size();
    int n2 = T.size();
    vector<int> dp(n2, -1);

    int length = INT_MAX;
    string ans = "";

    for (int i = 0; i < n1; i++) {
      for (int j = n2 - 1; j >= 0; j--) {
        if (T[j] == S[i]) {
          if (j == 0) {
            dp[j] = i;
          } else if (~dp[j - 1]) {
            dp[j] = dp[j - 1];
          }

          if (~dp[j] && j == n2 - 1) {
            if (i - dp[j] + 1 < length) {
              length = i - dp[j] + 1;
              ans = S.substr(dp[j], length);
            }
          }
        }
      }
    }
    return ans;
  }
};
