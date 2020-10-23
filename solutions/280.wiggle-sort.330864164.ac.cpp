class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      if (i % 2 == 0) {
        if (nums[i + 1] < nums[i])
          swap(nums[i + 1], nums[i]);
      } else {
        if (nums[i + 1] > nums[i])
          swap(nums[i + 1], nums[i]);
      }
    }
  }
};
