class Solution {
public:
  string destCity(vector<vector<string>> &paths) {
    unordered_map<string, int> mp;
    for (auto &p : paths) {
      mp[p[0]]++;
      mp[p[1]];
    }

    for (auto [k, v] : mp)
      if (v == 0)
        return k;

    return "";
  }
};
