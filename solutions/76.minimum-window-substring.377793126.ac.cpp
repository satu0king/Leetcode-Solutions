class Solution {
public:
  string minWindow(string s, string t) {
    map<char, int> mt;
    int l = 0, r = 0, cnt = 0;
    for (auto p : t) {
      mt[p]--;
    }
    string ans = "";
    while (r < s.size()) {
      if (mt[s[r]] < 0)
        cnt++;
      mt[s[r]]++;
      while (cnt == t.size()) {
        if (r - l + 1 < ans.size() || !ans.size()) {
          ans = s.substr(l, r - l + 1);
        }
        if (!mt[s[l]])
          cnt--;
        mt[s[l++]]--;
      }
      r++;
    }
    return ans;
  }
};
