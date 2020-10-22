class Solution {
public:
  int numberOfSubstrings(string s) {
    int a, b, c, l, ans;
    a = b = c = l = ans = 0;

    for (int r = 0; r < s.size(); r++) {
      if (s[r] == 'a')
        a++;
      if (s[r] == 'b')
        b++;
      if (s[r] == 'c')
        c++;
      while (a > 1 || b > 1 || c > 1) {
        if (s[l] == 'a' && a > 1) {
          a--;
          l++;
        } else if (s[l] == 'b' && b > 1) {
          b--;
          l++;
        } else if (s[l] == 'c' && c > 1) {
          c--;
          l++;
        } else
          break;
      }

      if (a && b && c)
        ans += l + 1;
    }
    return ans;
  }
};
