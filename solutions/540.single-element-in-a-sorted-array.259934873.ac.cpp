class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    int l = 0;
    int r = n - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (m % 2 == 1) {
        if (m && nums[m - 1] == nums[m])
          l = m + 1;
        else if (m < n - 1 && nums[m] == nums[m + 1])
          r = m - 1;
        else
          return nums[m];
      } else if (m % 2 == 0) {
        if (m && nums[m - 1] == nums[m])
          r = m - 1;
        else if (m < n - 1 && nums[m] == nums[m + 1])
          l = m + 1;
        else
          return nums[m];
      } else
        return nums[m];
    }

    throw "Error!";
  }
};
