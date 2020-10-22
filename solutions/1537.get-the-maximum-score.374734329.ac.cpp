class Solution {
  unordered_map<int, long> dp;
  vector<vector<int>> nums;

  long f(int i, int row, bool first = true) {
    int p = i * 4 + row * 2 + first;
    if (dp.count(p))
      return dp[p];

    int otherRow = (row + 1) % 2;

    long ans = 0;
    if (i == nums[row].size())
      return dp[p] = ans;

    ans = f(i + 1, row);
    if (first) {
      int j = getIndex(nums[otherRow], nums[row][i]);
      if (j != -1) {
        ans = max(ans, f(j, otherRow, false));
      }
      ans += nums[row][i];
    }
    return dp[p] = ans;
  }

  int getIndex(vector<int> &nums, int v) {
    auto it = lower_bound(nums.begin(), nums.end(), v);
    if (it == nums.end() || *it != v)
      return -1;
    return it - nums.begin();
  }

public:
  int maxSum(vector<int> &nums1, vector<int> &nums2) {
    nums.push_back(nums1);
    nums.push_back(nums2);
    const int p = 1e9 + 7;
    return max(f(0, 0), f(0, 1)) % p;
  }
};
