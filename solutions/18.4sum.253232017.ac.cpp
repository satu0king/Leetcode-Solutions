class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> path;
    ksum(nums, target, ans, path, 4);
    return ans;
  }
  void ksum(vector<int> &nums, int target, vector<vector<int>> &ans,
            vector<int> &path, int k = 3, int l = 0) {

    if (k == 2) {
      return twoSum(nums, target, ans, path, l);
    }

    int n = nums.size();
    for (int i = l; i < n; i++) {
      path.push_back(nums[i]);
      ksum(nums, target - nums[i], ans, path, k - 1, i + 1);
      path.pop_back();
      while (i < n - 1 && nums[i] == nums[i + 1])
        i++;
    }
  }

  void twoSum(vector<int> &nums, int target, vector<vector<int>> &ans,
              vector<int> &path, int l = 0) {

    int r = nums.size() - 1;

    while (l < r) {
      if (nums[l] + nums[r] == target) {
        path.push_back(nums[l]);
        path.push_back(nums[r]);
        ans.push_back(path);
        path.pop_back();
        path.pop_back();

        while (l < r && nums[l + 1] == nums[l])
          l++;
        while (l < r && nums[r - 1] == nums[r])
          r--;
        l++;
        r--;
      } else if (nums[l] + nums[r] > target)
        r--;
      else
        l++;
    }
  }
};
