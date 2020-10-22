class Solution {
public:
  int numSubseq(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long ans = 0;
    const long P = 1e9 + 7;
    int r = n - 1;
    int l = 0;
    vector<long> power(n + 1, 1);
    for (int i = 1; i <= n; i++)
      power[i] = (power[i - 1] * 2) % P;

    while (l <= r)
      if (nums[r] + nums[l] > target)
        r--;
      else
        ans = (ans + power[r - l++]) % P;

    return ans;
  }
};
