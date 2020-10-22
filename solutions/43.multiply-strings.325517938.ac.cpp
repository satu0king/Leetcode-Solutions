class Solution {
public:
  string multiply(string num1, string num2) {
    if (num2 == "0" || num1 == "0")
      return "0";
    string ans = "0";
    int shift = 0;

    for (int i = (int)num2.size() - 1; i >= 0; i--) {
      string temp = multiply(num1, num2[i] - '0') + string(shift++, '0');
      ans = add(ans, temp);
    }
    return ans;
  }

  string multiply(string &s1, int digit) {
    int n1 = s1.size();
    string ans = "";
    int i1 = n1 - 1;
    int c = 0;
    while (i1 >= 0 || c) {
      int v1 = (i1 >= 0 ? s1[i1--] - '0' : 0);
      ans += (v1 * digit + c) % 10 + '0';
      c = (v1 * digit + c) / 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }

  string add(string &s1, string &s2) {

    string ans = "";

    int n1 = s1.size();
    int n2 = s2.size();
    int i1 = n1 - 1;
    int i2 = n2 - 1;

    int c = 0;

    while (i1 >= 0 || i2 >= 0 || c) {

      int v1 = (i1 >= 0 ? s1[i1--] - '0' : 0);
      int v2 = (i2 >= 0 ? s2[i2--] - '0' : 0);
      ans += (v1 + v2 + c) % 10 + '0';
      c = (v1 + v2 + c) / 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
