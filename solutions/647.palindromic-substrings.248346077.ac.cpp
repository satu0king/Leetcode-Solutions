class Solution {

public:
  int countSubstrings(string s) {
    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
      f(s, i, i, ans);
      f(s, i, i + 1, ans);
    }

    return ans;
  }

  void f(string &s, int i, int j, int &ans) {

    while (i >= 0 && j < s.size())
      if (s[i--] == s[j++])
        ans++;
      else
        break;
  }
};
