class Solution {
public:
  string reformat(string s) {
    string digits;
    string chars;
    for (char c : s)
      if (isdigit(c))
        digits += c;
      else
        chars += c;

    if (digits.size() < chars.size())
      swap(digits, chars);

    if (digits.size() - chars.size() > 1)
      return "";

    for (int i = 0; i < digits.size(); i++)
      s[i * 2] = digits[i];

    for (int i = 0; i < chars.size(); i++)
      s[i * 2 + 1] = chars[i];

    return s;
  }
};
