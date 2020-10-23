class Solution {
public:
  vector<vector<string>> groupStrings(vector<string> &strings) {
    unordered_map<string, vector<string>> mp;
    for (auto &s : strings)
      mp[f(s)].push_back(s);
    vector<vector<string>> result;
    for (auto &p : mp)
      result.push_back(p.second);
    return result;
  }

  string f(string s) {
    char mi = s[0] - 'a';
    for (char &c : s)
      c = (c - 'a' - mi + 26) % 26 + 'a';
    return s;
  }
};
