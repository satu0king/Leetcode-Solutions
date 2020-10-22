class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (i == nums[i] - 1)
        continue;
      int t = nums[i];
      if (nums[t - 1] == t)
        continue;
      nums[i] = nums[t - 1];
      nums[t - 1] = t;
      i--;
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      if (i + 1 != nums[i])
        res.push_back(i + 1);
    }
    return res;
  }
};
