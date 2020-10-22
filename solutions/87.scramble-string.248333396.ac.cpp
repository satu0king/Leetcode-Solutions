class Solution {
public:
  bool isScramble(string s1, string s2) {

    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 != n2)
      return false;
    if (s1 == s2)
      return true;

    unordered_map<char, int> c1;
    unordered_map<char, int> c2;

    for (char c : s1)
      c1[c]++;
    for (char c : s2)
      c2[c]++;

    if (c1 != c2)
      return false;

    for (int i = 1; i < n1; i++) {

      if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
          isScramble(s1.substr(i), s2.substr(i)))
        return true;

      if (isScramble(s1.substr(0, i), s2.substr(n1 - i)) &&
          isScramble(s1.substr(i), s2.substr(0, n1 - i)))
        return true;
    }

    return false;
  }
};
