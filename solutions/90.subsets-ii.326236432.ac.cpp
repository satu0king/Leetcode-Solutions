class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> ans;
    vector<int> path;
    f(nums, ans, path);
    return vector<vector<int>>(ans.begin(), ans.end());
  }
  void f(vector<int> &nums, set<vector<int>> &ans, vector<int> &path,
         int i = 0) {
    if (i == nums.size()) {
      ans.insert(path);
      return;
    }

    f(nums, ans, path, i + 1);
    path.push_back(nums[i]);
    f(nums, ans, path, i + 1);
    path.pop_back();
  }
};
