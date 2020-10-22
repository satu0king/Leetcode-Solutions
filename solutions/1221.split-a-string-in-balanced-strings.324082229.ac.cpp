class Solution {
public:
  int balancedStringSplit(string s) {
    int count = 0;
    int ans = 0;
    for (char c : s) {
      count += c == 'L' ? -1 : 1;
      if (count == 0)
        ans++;
    }
    return ans;
  }
};
