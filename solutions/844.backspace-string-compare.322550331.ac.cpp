class Solution {
public:
  bool backspaceCompare(string S, string T) {

    int l = (int)S.size() - 1;
    int r = (int)T.size() - 1;

    int lb = 0;
    int rb = 0;

    while (l >= 0 || r >= 0) {
      if (l >= 0 && S[l] == '#') {
        l--;
        lb++;
      } else if (r >= 0 && T[r] == '#') {
        r--;
        rb++;
      } else if (lb) {
        lb--;
        l--;
      } else if (rb) {
        rb--;
        r--;
      } else if (l >= 0 && r >= 0 && S[l] == T[r]) {
        l--;
        r--;
      } else
        return false;
    }

    l = max(l, -1);
    r = max(r, -1);
    return l == r;
  }
};
