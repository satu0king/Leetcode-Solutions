class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int ans = 0;
    int l = 0;
    int r = 0;
    int n = s.size();
    vector<int> count(256);
    int uniqueCount = 0;
    while (r < n) {
      if (count[s[r++]]++ == 0)
        uniqueCount++;

      while (uniqueCount > k)
        if (--count[s[l++]] == 0)
          uniqueCount--;
      ans = max(ans, r - l);
    }
    return ans;
  }
};
