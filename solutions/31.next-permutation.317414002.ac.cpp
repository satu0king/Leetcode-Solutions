class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();

    int mx = nums.back();
    int i;
    for (i = n - 2; i >= 0; i--)
      if (nums[i] < nums[i + 1])
        break;

    if (~i) {
      int j = i + 1;
      for (int k = j; k < n; k++)
        if (nums[k] > nums[i] && nums[k] <= nums[j])
          j = k;

      swap(nums[i], nums[j]);
    }

    reverse(nums.begin() + i + 1, nums.end());
  }
};
