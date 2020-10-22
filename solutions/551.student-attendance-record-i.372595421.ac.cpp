class Solution {
public:
  bool checkRecord(string s) {
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A') {
        cnt++;
      }
    }
    if (cnt >= 2)
      return false;
    for (int i = 2; i < n; i++) {
      if (s[i] == s[i - 1] and s[i - 1] == s[i - 2] and s[i] == 'L') {
        return false;
      }
    }
    return true;
  }
};
