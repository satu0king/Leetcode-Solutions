class Solution {
  unordered_map<int, vector<int>> mp;

public:
  Solution(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++)
      mp[nums[i]].push_back(i);
  }

  int pick(int target) {
    auto &v = mp[target];
    return v[rand() % v.size()];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
