class Solution {
public:
  int titleToNumber(string s) {
    int ans = 0;

    for (char c : s) {
      ans = ans * 26 + (c - 'A' + 1);
    }
    return ans;
  }
};
