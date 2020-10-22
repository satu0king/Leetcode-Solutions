class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    int ans = 1;
    int t = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1])
        t++;
      else
        t = 1;
      ans = max(ans, t);
    }
    return ans;
  }
};
