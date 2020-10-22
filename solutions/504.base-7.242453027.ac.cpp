class Solution {
public:
  string convertToBase7(int num) {
    string base7 = "0123456";
    bool sign = num < 0;
    num = abs(num);
    string ans;

    do {
      ans = base7[num % 7] + ans;
    } while (num = num / 7);

    if (sign)
      ans = "-" + ans;
    return ans;
  }
};
