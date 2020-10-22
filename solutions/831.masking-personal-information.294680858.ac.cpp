class Solution {
public:
  string maskPII(string S) {
    int n = S.find("@");
    if (~n) {
      string result;
      result += tolower(S[0]); // First Letter of name1
      result += "*****";
      result += tolower(S[n - 1]); // Last Letter of name1

      for (char c : S.substr(n)) // @ followed by everything
        result += tolower(c);
      return result;
    } else {
      auto p = processNumber(S);
      string result;
      // cout << p.first <<" " << p.second;
      if (p.second > 10) {
        result += "+" + string(p.second - 10, '*') + "-";
      }
      result += "***-***-";
      result += p.first;
      return result;
    }
  }

  pair<string, int> processNumber(string num) {
    int digitCount = 0;
    string result;
    for_each(num.rbegin(), num.rend(), [&](char c) {
      if (isdigit(c)) {
        if (result.size() < 4)
          result += c;
        digitCount++;
      }
    });
    reverse(result.begin(), result.end());
    return make_pair(result, digitCount);
  }
};
