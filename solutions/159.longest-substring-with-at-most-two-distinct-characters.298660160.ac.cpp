class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int ans = 0;
    int l = 0;
    int r = 0;
    vector<int> mp(256);
    int uniqueCharacters = 0;
    while (r < s.size()) {
      if (!mp[s[r]])
        uniqueCharacters++;
      mp[s[r]]++;

      while (uniqueCharacters > 2) {
        mp[s[l]]--;
        if (!mp[s[l]])
          uniqueCharacters--;
        l++;
      }

      ans = max(r - l + 1, ans);
      r++;
    }
    return ans;
  }
};
