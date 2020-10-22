class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {

    int mp[40001] = {};
    int off = 20000;

    int ans = 0;
    for (int n : arr) {
      n += off;
      mp[n] = max(mp[n], 1 + mp[n - difference]);
      ans = max(ans, mp[n]);
    }
    return ans;
  }
};
