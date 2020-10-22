const int MOD = 1e9 + 7;
class Solution {
  map<pair<int, long>, int> mp;
  vector<unordered_set<int>> hats;

public:
  int numberWays(vector<vector<int>> &_hats) {
    mp.clear();

    for (auto &h : _hats)
      hats.push_back(unordered_set(h.begin(), h.end()));

    return dfs();
  }

  int dfs(int i = 1, long mask = 0) {

    long n = hats.size();

    auto p = make_pair(i, mask);

    if (mp.count(p))
      return mp[p];

    if (mask == (1 << n) - 1)
      return mp[p] = 1;

    if (i > 40)
      return 0;

    long ans = dfs(i + 1, mask);

    for (int j = 0; j < n; j++) {
      if (!(mask & 1L << j) && hats[j].count(i)) {
        mask ^= 1L << j;
        ans += dfs(i + 1, mask);
        ans %= MOD;
        mask ^= 1L << j;
      }
    }

    return mp[p] = ans;
  }
};
