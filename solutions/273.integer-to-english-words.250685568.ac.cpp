class Solution {
  vector<string> lessthan20;
  vector<string> tens;
  vector<string> thousands;

public:
  string numberToWords(int n) {
    lessthan20 = {"",        "One",     "Two",       "Three",    "Four",
                  "Five",    "Six",     "Seven",     "Eight",    "Nine",
                  "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                  "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    tens = {"",      "Ten",   "Twenty",  "Thirty", "Forty",
            "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    thousands = {"", " Thousand ", " Million ", " Billion "};

    string res = "";

    if (n == 0)
      return "Zero";

    for (int i = 0; n; i++) {
      if (n % 1000)
        res = helper(n) + thousands[i] + res;
      n /= 1000;
    }

    return strip(res);
  }

  string strip(string s) {
    string ans = "";

    string temp = "";

    for (char c : s) {
      if (c == ' ') {
        if (temp.size()) {
          if (ans.size())
            ans += " " + temp;
          else
            ans = temp;
        }
        temp = "";
      } else
        temp += c;
    }

    if (temp.size()) {
      if (ans.size())
        ans += " " + temp;
      else
        ans = temp;
    }

    return ans;
  }

  string helper(int n) {
    n %= 1000;
    if (n < 20)
      return lessthan20[n];
    if (n < 100)
      return tens[n / 10] + " " + lessthan20[n % 10];

    return lessthan20[n / 100] + " Hundred " + helper(n % 100);
  }
};
