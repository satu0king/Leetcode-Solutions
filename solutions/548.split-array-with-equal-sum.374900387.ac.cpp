class Solution {
public:
  bool splitArray(vector<int> &nums) {

    int n = nums.size();
    for (int i = 1; i < n; i++)
      nums[i] += nums[i - 1];

    for (int j = 3; j + 3 < n; j++) {
      unordered_set<int> set;
      for (int i = 1; i + 1 < j; i++) {
        int s1 = nums[i - 1];
        int s2 = nums[j - 1] - nums[i];
        if (s1 == s2) {
          set.insert(s1);
        }
      }
      for (int k = j + 2; k + 1 < n; k++) {
        int s3 = nums[k - 1] - nums[j];
        int s4 = nums[n - 1] - nums[k];
        if (s3 == s4 && set.count(s3))
          return true;
      }
    }
    return false;
  }
};

// leftSum - num = rightSum - x
