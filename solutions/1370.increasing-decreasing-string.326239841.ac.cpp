class Solution {
public:
  string sortString(string s) {
    vector<int> mp(256);
    string result;
    for (char c : s)
      mp[c]++;

    while (result.size() < s.size()) {
      for (char i = 'a'; i <= 'z'; i++)
        if (mp[i]-- > 0)
          result += i;

      for (char i = 'z'; i >= 'a'; i--)
        if (mp[i]-- > 0)
          result += i;
    }
    return result;
  }
};
