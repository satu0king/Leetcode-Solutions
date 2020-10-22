class Solution {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    int offset = 0;
    int l = 1;
    int r = n - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] < nums[0]) {
        offset = m;
        r = m - 1;
      } else
        l = m + 1;
    }

    l = 0;
    r = n - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      int mr = (m + offset) % n;
      if (nums[mr] == target)
        return mr;
      else if (nums[mr] > target)
        r = m - 1;
      else
        l = m + 1;
    }
    return -1;
  }
};
