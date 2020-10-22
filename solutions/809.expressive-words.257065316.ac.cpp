class Solution {
public:
  int expressiveWords(string S, vector<string> &words) {

    auto f_s = f(S);
    int ans = 0;
    for (string &w : words)
      if (cmp(f(w), f_s))
        ans++;

    return ans;
  }

  vector<pair<char, int>> f(string &s) {
    char prev = '.';
    int count = 0;
    vector<pair<char, int>> res;

    for (char c : s) {
      if (c == prev)
        count++;
      else {
        if (count)
          res.emplace_back(prev, count);
        count = 1;
        prev = c;
      }
    }

    if (count)
      res.emplace_back(prev, count);

    return res;
  }

  bool cmp(vector<pair<char, int>> p1, vector<pair<char, int>> &p2) {
    if (p1.size() != p2.size())
      return false;
    int n = p1.size();
    for (int i = 0; i < n; i++) {
      if (p1[i].first != p2[i].first)
        return false;
      if (p1[i].second > p2[i].second)
        return false;
      if (p1[i].second == p2[i].second)
        continue;
      if (p2[i].second < 3)
        return false;
    }
    return true;
  }
};
