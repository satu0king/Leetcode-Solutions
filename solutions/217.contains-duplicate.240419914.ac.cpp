class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    set<int> mp;
    for (auto num : nums)
      if (mp.find(num) == mp.end())
        mp.insert(num);
      else
        return true;
    return false;
  }
};
