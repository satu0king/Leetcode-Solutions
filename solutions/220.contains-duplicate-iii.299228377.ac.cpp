class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, long long int k,
                                     long long int t) {
    map<long long int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
      auto it = mp.lower_bound(nums[i] - t);
      if (it != mp.end() && it->first <= nums[i] + t) {
        return true;
      }

      mp[nums[i]]++;

      if (i - k >= 0) {
        mp[nums[i - k]]--;
        if (mp[nums[i - k]] == 0)
          mp.erase(nums[i - k]);
      }
    }
    return false;
  }
};
