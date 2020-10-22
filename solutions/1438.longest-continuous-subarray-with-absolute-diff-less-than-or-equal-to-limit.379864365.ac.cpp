class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {

    int n = nums.size();

    if (n == 0)
      return 0;

    multiset<int> s;

    int l = 0;
    int ans = 1;

    for (int r = 0; r < n; r++) {
      s.insert(nums[r]);
      while (l < r && (((*s.rbegin()) - (*s.begin())) > limit)) {
        s.erase(s.find(nums[l]));
        l++;
      }

      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
