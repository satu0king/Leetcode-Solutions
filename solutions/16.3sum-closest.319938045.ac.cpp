class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int n = nums.size();

    int ans = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++) {
      int t = target - nums[i];

      int l = i + 1;
      int r = n - 1;

      int ans2 = nums[i + 1] + nums[i + 2];

      while (l < r) {

        if (abs(nums[l] + nums[r] - t) < abs(ans2 - t))
          ans2 = nums[l] + nums[r];

        if (nums[l] + nums[r] < t)
          l++;
        else
          r--;
      }

      if (abs(ans2 + nums[i] - target) < abs(ans - target))
        ans = ans2 + nums[i];
    }

    return ans;
  }
};
