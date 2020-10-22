class Solution {
public:
  int longestArithSeqLength(vector<int> &A) {

    // unordered_multiset<int> A_set(A.begin(), A.end());
    unordered_map<int, int> mp;
    for (int a : A)
      mp[a]++;
    int ans = 0;

    int n = A.size();
    vector<unordered_map<int, int>> dp(n);

    for (int i = 0; i < n; i++) {
      mp[A[i]]--;
      for (int j = 0; j < i; j++) {
        int d = A[i] - A[j];
        int s;
        if (dp[j].count(d))
          s = dp[j][d] + 1;
        else
          s = 2;

        if (mp[A[i] + d])
          dp[i][d] = s;
        else
          ans = max(ans, s);
      }
    }

    return ans;
  }
};
