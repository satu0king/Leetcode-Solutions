class Solution {
public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
    int n = s.size();
    vector<int> masks(n);

    for (int i = 0; i < n; i++) {
      masks[i] = i ? masks[i - 1] : 0;
      masks[i] = masks[i] ^ (1 << (s[i] - 'a'));
    }

    vector<bool> ans;
    for (auto &q : queries) {
      int l = q[0];
      int r = q[1];
      int k = q[2];
      int t = 0;
      int mask = masks[r] ^ (l ? masks[l - 1] : 0);

      while (mask) {
        mask = mask & (mask - 1);
        t++;
      }
      ans.push_back(k >= t / 2);
    }
    return ans;
  }
};
