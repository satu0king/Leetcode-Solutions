class Solution {

  map<pair<int, int>, bool> mp;

public:
  bool isMatch(string &s, string &p, int i = 0, int j = 0) {

    auto _p = make_pair(i, j);
    if (mp.count(_p))
      return mp[_p];

    bool ans;

    if (j == p.size()) {
      ans = (i == s.size());
    } else {
      bool first_match = (i < s.size()) && (p[j] == s[i] || p[j] == '.');

      if (j + 1 < p.size() && p[j + 1] == '*')
        ans =
            isMatch(s, p, i, j + 2) || (first_match && isMatch(s, p, i + 1, j));
      else
        ans = first_match && isMatch(s, p, i + 1, j + 1);
    }

    mp[_p] = ans;

    return mp[_p];
  }
};
