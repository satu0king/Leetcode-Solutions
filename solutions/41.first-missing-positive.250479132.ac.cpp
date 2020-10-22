class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1 && nums[i] <= n && nums[i] > 0) {
        if (nums[nums[i] - 1] != nums[i]) {
          swap(nums[nums[i] - 1], nums[i]);
          i--;
        }
      }
    }

    int i;
    for (i = 0; i < n; i++) {
      if (nums[i] != i + 1)
        break;
    }
    return i + 1;
  }
};
