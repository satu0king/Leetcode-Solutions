class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (int a : nums)
      ans += mp[a]++;
    return ans;
  }
};
