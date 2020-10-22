class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int ans = 0;
    unordered_set<char> ch;
    int l = 0, r = 0;
    while (r < n) {
      while (r < n && !ch.count(s[r])) {
        ch.insert(s[r]);
        r++;
      }
      // cout << l << " " << r << endl;
      ans = max(ans, r - l);
      while (l < n && s[l] != s[r]) {
        ch.erase(s[l]);
        l++;
      }
      l++;
      r++;
    }
    return ans;
  }
};
