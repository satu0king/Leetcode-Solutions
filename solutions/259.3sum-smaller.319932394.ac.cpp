class Solution {
public:
  int threeSumSmaller(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
      ans += twoSumSmaller(nums, target - nums[i], i + 1);
    return ans;
  }

  int twoSumSmaller(vector<int> &nums, int target, int i) {
    int l = i;
    int n = nums.size();
    int r = n - 1;
    int ans = 0;

    while (l < r) {
      if (nums[l] + nums[r] < target) {
        ans += r - l;
        l++;
      } else
        r--;
    }

    return ans;
  }
};
