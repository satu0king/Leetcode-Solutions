class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int n = nums.size();
    int ans = 0;

    int l = 0;
    int r = 0;

    int currentProduct = 1;

    while (r < n) {

      currentProduct *= nums[r++];
      while (l < r && currentProduct >= k)
        currentProduct /= nums[l++];
      ans += r - l;
    }

    return ans;
  }
};
