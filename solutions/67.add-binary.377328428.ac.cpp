class Solution {
public:
  string addBinary(string a, string b) {
    int n = a.size();
    int m = b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    string ans = "";
    int i;
    for (i = 0; i < min(n, m); i++) {
      int p = a[i] - '0';
      int q = b[i] - '0';
      int r = (p + q + carry) % 2;
      carry = (p + q + carry) / 2;
      ans += char('0' + r);
    }
    for (; i < n; i++) {
      int p = a[i] - '0';
      int q = 0;
      int r = (p + q + carry) % 2;
      carry = (p + q + carry) / 2;
      ans += char('0' + r);
    }
    for (; i < m; i++) {
      int p = 0;
      int q = b[i] - '0';
      int r = (p + q + carry) % 2;
      carry = (p + q + carry) / 2;
      ans += char('0' + r);
    }
    if (carry)
      ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
