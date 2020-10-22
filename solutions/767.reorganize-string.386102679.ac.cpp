class Solution {
public:
  string reorganizeString(string S) {
    int n = S.size();
    set<pair<int, char>, greater<pair<int, char>>> s;
    map<char, int> ma;
    for (auto &e : S)
      ma[e]++;
    for (auto &e : ma)
      s.insert({e.second, e.first});
    string ans;
    char prev = ' ';
    while (n--) {
      auto top = *s.begin();
      s.erase(s.begin());
      char c = top.second;
      int count = top.first;
      if (c == prev) {
        if (s.size() == 0)
          return "";
        auto ttop = *s.begin();
        s.erase(s.begin());
        s.insert({count, c});
        // cout << "c = " << c << " top " << ttop.second << endl;
        c = ttop.second;
        count = ttop.first;
      }
      ans += c;
      if (count - 1)
        s.insert({count - 1, c});
      prev = c;
    }
    return ans;
  }
};
