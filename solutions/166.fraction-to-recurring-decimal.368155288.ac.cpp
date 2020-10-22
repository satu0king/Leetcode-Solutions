class Solution {
public:
  string fractionToDecimal(long numerator, long denominator) {
    string ans = "";
    if (numerator == 0)
      return "0";
    if (numerator < 0 ^ denominator < 0)
      ans = "-";
    numerator = abs(numerator);
    denominator = abs(denominator);
    ans += to_string(numerator / denominator);
    numerator %= denominator;
    if (numerator == 0)
      return ans;
    unordered_map<int, int> mp;
    ans += '.';
    while (numerator) {
      if (mp.count(numerator)) {
        ans.insert(ans.begin() + mp[numerator], '(');
        ans += ')';
        return ans;
      }
      mp[numerator] = ans.size();
      numerator = numerator * 10;
      ans += to_string(numerator / denominator);
      numerator %= denominator;
    }
    return ans;
  }
};
