class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    if (nums.size() < 2)
      return 0;

    int mx1 = 0;
    int mx2 = 1;

    if (nums[0] < nums[1])
      swap(mx1, mx2);

    for (int i = 2; i < nums.size(); i++) {
      if (nums[i] >= nums[mx1]) {
        mx2 = mx1;
        mx1 = i;
      } else if (nums[i] > nums[mx2]) {
        mx2 = i;
      }
    }

    return nums[mx1] >= 2 * nums[mx2] ? mx1 : -1;
  }
};
