class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    if (k == 0) {
      int sum = 0;
      unordered_set<int> seen;
      int prev = 0;
      for (int n : nums) {
        sum += n;
        if (seen.count(sum))
          return true;
        seen.insert(prev);
        prev = sum;
      }

      return false;
    }

    int prev = 0;
    unordered_set<int> seen;
    int sum = 0;

    for (int n : nums) {
      sum += n;
      sum %= k;
      if (seen.count(sum))
        return true;
      seen.insert(prev);
      prev = sum;
    }

    return false;
  }
};
