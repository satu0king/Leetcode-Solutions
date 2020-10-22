class Solution {
public:
  int numSub(string s) {
    long int ans = 0;
    int count = 0;
    for (char c : s) {
      if (c == '0')
        count = 0;
      else
        count++;
      ans += count;
    }
    const int p = 1e9 + 7;
    return ans % p;
  }
};
