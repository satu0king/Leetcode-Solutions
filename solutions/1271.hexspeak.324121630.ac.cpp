class Solution {
public:
  string toHexspeak(string num) {
    string ans;
    long long n = stol(num);
    while (n) {
      int d = n % 16;
      if (d == 0)
        ans += "O";
      else if (d == 1)
        ans += "I";
      else if (d >= 10)
        ans += 'A' + (d - 10);
      else
        return "ERROR";

      n /= 16;
    }

    reverse(begin(ans), end(ans));

    return ans;
  }
};
