class Solution {
public:
  int minDifference(vector<int> &nums) {
    if (nums.size() <= 4)
      return 0;
    sort(nums.begin(), nums.end());
    int ans = nums[nums.size() - 1 - 3] - nums[0];
    for (int i = 1; i <= 3; i++) {
      ans = min(ans, nums[nums.size() - 1 - (3 - i)] - nums[i]);
    }
    return ans;
  }
};
