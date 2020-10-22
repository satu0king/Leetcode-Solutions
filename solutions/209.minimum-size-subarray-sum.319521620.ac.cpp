class Solution {
public:
  int minSubArrayLen(int s, vector<int> &nums) {
    int n = nums.size();

    int ans = n + 1;
    int l = 0;
    int sum = 0;
    for (int r = 0; r < n; r++) {
      sum += nums[r];
      // cout << r << endl;
      while (sum >= s + nums[l]) {
        sum -= nums[l++];
      }

      if (sum >= s)
        ans = min(ans, r - l + 1);
    }
    return ans == n + 1 ? 0 : ans;
  }
};
