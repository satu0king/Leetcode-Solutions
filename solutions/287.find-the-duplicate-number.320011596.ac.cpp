class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] == i)
        continue;
      if (nums[nums[i]] == nums[i])
        return nums[i];
      swap(nums[i], nums[nums[i]]);
      i--;
    }

    return n + 1;
  }
};
