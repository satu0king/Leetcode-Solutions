class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int ans = INT_MIN;
    int mn = 0;
    int cumSum = 0;
    for (int n : nums) {
      cumSum += n;
      ans = max(ans, cumSum - mn);
      mn = min(mn, cumSum);
    }
    return ans;
  }
};
