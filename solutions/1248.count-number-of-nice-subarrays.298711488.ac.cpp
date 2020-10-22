class Solution {
public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    int ans = 0;
    int l1 = 0;
    int l2 = 0;
    int c1 = 0;
    int c2 = 0;
    for (int r = 0; r < nums.size(); r++) {
      if (nums[r] % 2) {
        c1++;
        c2++;
      }
      while (c1 >= k)
        if (nums[l1++] % 2)
          c1--;
      while (c2 > k)
        if (nums[l2++] % 2)
          c2--;
      ans += l1 - l2;
    }
    return ans;
  }
};
