class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int ans = 0;
    int zeroCount = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      if (nums[r] == 0)
        zeroCount++;
      while (zeroCount > 1)
        if (nums[l++] == 0)
          zeroCount--;
      ans = max(r - l, ans);
    }
    return ans;
  }
};
