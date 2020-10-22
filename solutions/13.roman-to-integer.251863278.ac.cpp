class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> mp = {
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };
    int i = 0;
    int j = 1;
    int sum = 0;
    for (; j < s.size(); i++, j++)
      if (mp[s[i]] < mp[s[j]])
        sum -= mp[s[i]];
      else
        sum += mp[s[i]];

    sum += mp[s[i]];

    return sum;
  }
};
