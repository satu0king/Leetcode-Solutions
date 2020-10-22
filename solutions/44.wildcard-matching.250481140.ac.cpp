class Solution {
public:
  bool isMatch(string s, string p) {

    int i = 0;
    int j = 0;

    int star = -1;
    int prevS = -1;

    int n1 = s.size();
    int n2 = p.size();

    while (i < n1) {

      if (j < n2 && (s[i] == p[j] || p[j] == '?')) {
        i++;
        j++;
        continue;
      }

      if (j < n2 && p[j] == '*') {
        star = j;
        j++;
        prevS = i;
        continue;
      }

      if (~star) {
        i = ++prevS;
        j = star + 1;
        continue;
      }

      return false;
    }

    while (j < n2 && p[j] == '*')
      j++;

    return j == n2;
  }
};
