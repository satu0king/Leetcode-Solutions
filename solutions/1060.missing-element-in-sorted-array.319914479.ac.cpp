class Solution {
public:
  int missingElement(vector<int> &nums, int k) {
    int ans = 1;
    int missing = (nums.back() - nums.front() + 1) - nums.size();
    if (missing < k)
      return nums.back() + k - missing;

    int l = 0;
    int r = nums.size() - 2;

    while (l <= r) {
      int m = (l + r) / 2;

      int missing = nums[m] - nums[0] - m;
      int nextMissing = nums[m + 1] - nums[0] - (m + 1);

      if (k > nextMissing)
        l = m + 1;
      else if (k < missing)
        r = m - 1;
      else
        return nums[m] + k - missing;
    }

    return -1;
  }
};
