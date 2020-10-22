class Solution {
public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    int l = 1;
    int r = *max_element(nums.begin(), nums.end());
    int ans;
    while (l <= r) {
      int m = (l + r) / 2;
      int temp = 0;
      for (int a : nums)
        temp += (a + m - 1) / m;
      if (temp <= threshold) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};
