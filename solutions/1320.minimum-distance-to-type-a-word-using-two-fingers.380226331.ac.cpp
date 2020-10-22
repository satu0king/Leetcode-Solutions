class Solution {
public:
  vector<vector<vector<int>>> dp;
  string word;
  int n;

  pair<int, int> position(int c) { return make_pair(c / 6, c % 6); }

  int cost(int a, int b) {
    pair<int, int> aa = position(a);
    pair<int, int> bb = position(b);

    return abs(aa.first - bb.first) + abs(aa.second - bb.second);
  }

  int recurse(int idx, int h1, int h2) {
    if (idx == n)
      return 0;

    int &ans = dp[idx][h1][h2];

    if (ans != -1)
      return ans;

    ans = 1e9 + 7;

    int c = word[idx] - 'A';

    ans = min(ans, cost(h1, c) + recurse(idx + 1, c, h2));
    ans = min(ans, cost(h2, c) + recurse(idx + 1, h1, c));

    return ans;
  }

  int minimumDistance(string word) {
    this->word = word;
    n = word.size();
    dp.clear();
    dp.assign(n, vector<vector<int>>(26, vector<int>(26, -1)));
    int ans = 1e9 + 7;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        ans = min(ans, recurse(0, i, j));
      }
    }
    return ans;
  }
};
