class Solution {
public:
  int minimumSwap(string s1, string s2) {
    int x1 = 0;
    int x2 = 0;
    for (char c : s1)
      if (c == 'x')
        x1++;
    for (char c : s2)
      if (c == 'x')
        x2++;

    if (x1 % 2 != x2 % 2)
      return -1;

    int ans = 0;
    int xy = 0;
    int yx = 0;
    for (int i = 0; i < s1.size(); i++)
      if (s1[i] != s2[i] && s1[i] == 'x')
        xy++;
      else if (s1[i] != s2[i] && s1[i] == 'y')
        yx++;

    return (xy + 1) / 2 + (yx + 1) / 2;
  }
};
