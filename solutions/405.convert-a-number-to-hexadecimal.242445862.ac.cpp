class Solution {
public:
  string toHex(unsigned int num) {
    string map = "0123456789abcdef";
    string ans;
    do {
      ans += map[num % 16];
      num /= 16;
    } while (num);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
