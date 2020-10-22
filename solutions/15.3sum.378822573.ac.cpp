class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> path;
    kSum(nums, path, ans);
    return ans;
  }

  void kSum(vector<int> &nums, vector<int> &path, vector<vector<int>> &ans,
            int target = 0, int k = 3, int l = 0) {
    if (k == 2) {
      twoSum(nums, path, ans, target, l);
    } else {
      for (int i = l; i < nums.size(); i++) {
        path.push_back(nums[i]);
        kSum(nums, path, ans, target - nums[i], k - 1, i + 1);
        path.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
          i++;
      }
    }
  }

  void twoSum(vector<int> &nums, vector<int> &path, vector<vector<int>> &ans,
              int target = 0, int l = 0) {
    int r = nums.size() - 1;

    while (l < r) {
      if (nums[l] + nums[r] == target) {
        path.push_back(nums[l]);
        path.push_back(nums[r]);
        ans.push_back(path);
        path.pop_back();
        path.pop_back();
        while (l < r && nums[l] == nums[l + 1])
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
