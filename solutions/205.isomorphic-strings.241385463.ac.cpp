class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size())
      return false;
    unordered_map<char, char> mp;
    unordered_set<char> set;
    int n = s.size();

    for (int i = 0; i < n; i++) {
      if (mp.find(s[i]) == mp.end()) {
        if (set.find(t[i]) != set.end())
          return false;
        set.insert(t[i]);
        mp[s[i]] = t[i];
      } else if (mp[s[i]] != t[i])
        return false;
    }

    return true;
  }
};
