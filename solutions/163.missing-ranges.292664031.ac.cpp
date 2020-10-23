class Solution {
public:
  vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
    long long int next = lower;
    vector<string> ans;
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == next) {
        next++;
        continue;
      } else {
        ans.push_back(f(next, nums[i] - 1));
        next = nums[i] + 1LL;
      }
    }
    if (next <= upper)
      ans.push_back(f(next, upper));
    return ans;
  }

  string f(int l, int r) {
    if (l == r)
      return to_string(l);
    return to_string(l) + "->" + to_string(r);
  }
};
