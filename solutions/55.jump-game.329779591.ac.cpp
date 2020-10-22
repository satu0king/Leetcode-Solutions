class Solution {
public:
  bool canJump(vector<int> &nums) {
    int mx = 0;
    int n = nums.size();
    for (int i = 0; i <= min(mx, n - 1); i++)
      mx = max(mx, nums[i] + i);

    return mx >= n - 1;
  }
};
