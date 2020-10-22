class Solution {
public:
  vector<int> shuffle(vector<int> &nums, int n) {
    for (int i = 0; i < 2 * n; i++) {
      if (nums[i] < 0)
        continue;
      int el = nums[i];
      int j = i;
      do {
        int k = j < n ? 2 * j : (j - n) * 2 + 1;
        int t = nums[k];
        nums[k] = -el;
        j = k;
        el = t;
      } while (j != i);
    }
    for (int &a : nums)
      a = -a;
    return nums;
  }
};
