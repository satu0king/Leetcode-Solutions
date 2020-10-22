

class Solution {
public:
  int oddEvenJumps(vector<int> &a) {

    int n = a.size();
    vector<int> maxSet;
    vector<int> minSet;
    vector<vector<bool>> dp(n, vector<bool>(2));
    dp[n - 1][0] = true;
    dp[n - 1][1] = true;
    int ans = 1;

    map<int, int> mp;
    mp[a[n - 1]] = n - 1;

    for (int i = n - 2; i >= 0; i--) {
      auto it = mp.lower_bound(a[i]);
      if (it != mp.end()) {
        dp[i][0] = dp[it->second][1];
        ans += dp[i][0];
      }
      it = mp.upper_bound(a[i]);
      if (it != mp.begin()) {
        it = prev(it);
        dp[i][1] = dp[it->second][0];
      }
      mp[a[i]] = i;
    }

    return ans;
  }
};
