class Solution {
public:
  bool isOneEditDistance(string s, string t) {

    if (s.size() > t.size())
      swap(s, t);

    int n1 = s.size();
    int n2 = t.size();

    if (n2 - n1 > 1)
      return false;

    if (n1 == n2) {
      int misses = 0;
      for (int i = 0; i < n1; i++)
        misses += (s[i] != t[i]);
      return misses == 1;
    } else {
      int i = 0;
      for (; i < n1; i++) {
        if (s[i] != t[i])
          break;
      }
      i++;
      for (; i < n2; i++) {
        if (s[i - 1] != t[i])
          break;
      }
      return i == n2;
    }
  }
};
