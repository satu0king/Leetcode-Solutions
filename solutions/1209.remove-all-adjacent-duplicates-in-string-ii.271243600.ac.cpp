class Solution {
public:
  string removeDuplicates(string s, int k) {
    auto a = f1(s);
    while (true) {
      string t = s;
      f3(a, k);
      s = f2(a);
      a = f1(s);
      if (s == t)
        break;
    }

    return f2(a);
  }

  vector<pair<char, int>> f1(string s) {
    vector<pair<char, int>> ans;
    for (char c : s) {
      if (ans.size() && ans.back().first == c)
        ans.back().second++;
      else
        ans.emplace_back(c, 1);
    }
    return ans;
  }

  string f2(vector<pair<char, int>> &arr) {
    string s = "";
    for (auto p : arr)
      s += string(p.second, p.first);
    return s;
  }

  void f3(vector<pair<char, int>> &arr, int k) {
    for (auto &p : arr)
      if (p.second >= k)
        p.second -= k;
  }
};
