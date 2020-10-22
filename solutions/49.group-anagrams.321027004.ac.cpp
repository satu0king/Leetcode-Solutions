class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    auto f = [](string &s) {
      vector<int> r(26);
      for (int c : s)
        r[c - 'a']++;
      return r;
    };
    map<vector<int>, vector<string>> mp;

    for (string &s : strs)
      mp[f(s)].push_back(s);

    vector<vector<string>> ans;

    for (auto &p : mp)
      ans.push_back(p.second);

    return ans;
  }
};
