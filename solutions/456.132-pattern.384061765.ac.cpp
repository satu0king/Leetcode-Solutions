class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    int n = nums.size();
    multiset<int> pre;
    for (int i = 0; i < n; i++) {
      pre.insert(nums[i]);
    }
    int mi = 1e9 + 1;
    for (int i = 0; i < n; i++) {
      pre.erase(pre.find(nums[i]));
      if (mi < nums[i]) {
        auto up = pre.upper_bound(mi);
        if (up != pre.end() && (*up) < nums[i]) {
          return true;
        }
      }
      mi = min(mi, nums[i]);
    }
    return false;
  }
};
