class Solution {
public:
  int lenLongestFibSubseq(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n));

    unordered_map<int, int> mp;

    int ans = 0;

    for (int i = 0; i < n; i++) {
      mp[A[i]] = i;

      for (int j = i - 1; j >= 0 && A[j] > A[i] / 2; j--) {

        if (mp.count(A[i] - A[j])) {
          int k = mp[A[i] - A[j]];
          dp[j][i] = max(dp[k][j] + 1, 3);
          ans = max(ans, dp[j][i]);
          // cout << A[i] <<" " << A[j] <<" " <<A[k] <<" " << dp[j][i] << endl;
        }
      }
    }

    return ans;
  }
};
