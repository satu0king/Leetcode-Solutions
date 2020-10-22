class Solution {
public:
  int minInsertions(string s) {
    int ans = 0;
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        count++;
      else {
        if (i + 1 < s.size() && s[i + 1] == ')') {
          i++;
          if (count > 0) {
            count--;
          } else {
            ans++;
          }
        } else {
          if (count > 0) {
            count--;
            ans++;
          } else {
            ans += 2;
          }
        }
      }
    }
    ans += count * 2;
    return ans;
  }
};
