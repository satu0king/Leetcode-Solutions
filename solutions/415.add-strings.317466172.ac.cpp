class Solution {
public:
  string addStrings(string num1, string num2) {
    string result;

    int i = num1.size();
    int j = num2.size();
    int c = 0;

    while (i || j || c) {
      int r = (i ? num1[--i] - '0' : 0) + (j ? num2[--j] - '0' : 0) + c;
      c = r / 10;
      result += (r % 10) + '0';
    }

    reverse(result.begin(), result.end());
    return result;
  }
};
