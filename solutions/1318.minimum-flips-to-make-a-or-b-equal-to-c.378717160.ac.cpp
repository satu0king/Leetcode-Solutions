class Solution {
public:
  int minFlips(int a, int b, int c) {
    int ans = 0;
    for (int i = 0; i < 31; i++) {
      int ai = a & (1 << i);
      int bi = b & (1 << i);
      int ci = c & (1 << i);
      if ((ai | bi) == ci)
        continue;
      if (ci)
        ans++;
      else if (ai && bi)
        ans += 2;
      else
        ans++;
    }
    return ans;
  }
};
