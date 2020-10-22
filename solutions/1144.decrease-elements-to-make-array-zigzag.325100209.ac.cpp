class Solution {
public:
  int movesToMakeZigzag(vector<int> &nums) {
    int ans = f(nums);
    nums.insert(nums.begin(), 0);
    ans = min(ans, f(nums));
    return ans;
  }

  int f(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i += 2) {
      int l = i ? nums[i - 1] : 2000;
      int r = i + 1 < nums.size() ? nums[i + 1] : 2000;
      ans += max(nums[i] - (min(l, r) - 1), 0);
    }
    return ans;
  }
};
