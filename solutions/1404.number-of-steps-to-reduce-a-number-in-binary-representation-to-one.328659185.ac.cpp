class Solution {
public:
  int numSteps(string s) {
    reverse(s.begin(), s.end());
    int ans = 0;
    int carry = 0;
    int i = 0;
    while (i < s.size() - 1) {
      int t = carry + (i < s.size() ? s[i++] - '0' : 0);
      if (t % 2) {
        t++;
        ans++;
      }
      carry = t / 2;
      ans++;
    }
    if (carry)
      ans++;
    return ans;
  }
};
