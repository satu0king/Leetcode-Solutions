class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
      int m = (l + r) / 2;
      if (m + 1 < nums.size() && nums[m + 1] > nums[m])
        l = m + 1;
      else if (m - 1 >= 0 && nums[m - 1] > nums[m])
        r = m - 1;
      else
        return m;
    }

    return -1;
  }
};
