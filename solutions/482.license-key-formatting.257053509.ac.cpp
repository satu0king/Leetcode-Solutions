class Solution {
public:
  string licenseKeyFormatting(string S, int k) {
    S = removeDashes(S);
    int n = S.size();
    int r = n % k;
    if (r == 0)
      r = k;
    string ans = S.substr(0, r);
    for (int i = r; i < n; i += k)
      ans += "-" + S.substr(i, k);
    return ans;
  }

  string removeDashes(string s) {
    string ans = "";
    for (char c : s) {
      if (c != '-')
        ans += to_upper(c);
    }
    return ans;
  }

  char to_upper(char c) {
    if (c >= 'a' && c <= 'z')
      c = c - 'a' + 'A';
    return c;
  }
};
