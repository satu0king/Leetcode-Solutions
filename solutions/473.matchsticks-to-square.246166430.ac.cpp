class Solution {
public:
  bool makesquare(vector<int> &nums) {

    return nums.size() && canPartitionKSubsets(nums, 4);
  }

  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int sm = 0;
    for (int n : nums)
      sm += n;

    if (sm % k)
      return false;
    sm /= k;

    int n = nums.size();
    vector<bool> visited(n);

    return f(nums, visited, k, sm);
  }

  bool f(vector<int> &nums, vector<bool> &visited, int k, int target, int j = 0,
         int currentSum = 0) {
    if (k == 0)
      return true;

    if (currentSum == target)
      return f(nums, visited, k - 1, target);

    for (int i = j; i < nums.size(); i++) {
      if (!visited[i] && nums[i] <= target - currentSum) {
        visited[i] = true;
        if (f(nums, visited, k, target, i + 1, currentSum + nums[i])) {
          // visited[i] = false;
          return true;
        }
        visited[i] = false;
      }
    }

    return false;
  }
};
