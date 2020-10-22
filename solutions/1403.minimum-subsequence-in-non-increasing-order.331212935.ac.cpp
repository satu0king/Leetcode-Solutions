class Solution {
public:
  vector<int> minSubsequence(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    sort(nums.rbegin(), nums.rend());

    int s = 0;
    vector<int> ans;
    for (int a : nums) {
      ans.push_back(a);
      s += a;
      if (s > sum - s)
        return ans;
    }
    return {};
  }
};
