class Solution {
public:
  int triangleNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    int n = nums.size();

    for (int i = n - 2; i >= 0; i--) {
      for (int j = i - 1; j >= 0; j--) {
        auto it =
            lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + nums[j]);
        ans += it - (nums.begin() + i + 1);
      }
    }
    return ans;
  }
};
