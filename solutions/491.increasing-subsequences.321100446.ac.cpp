class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<int> path;
    vector<vector<int>> ans;
    dfs(nums, path, ans);

    return ans;
  }

  void dfs(vector<int> &nums, vector<int> &path, vector<vector<int>> &ans,
           int i = 0) {
    if (path.size() > 1)
      ans.push_back(path);
    unordered_set<int> done;
    for (int j = i; j < nums.size(); j++) {
      if ((path.empty() || path.back() <= nums[j]) && !done.count(nums[j])) {
        done.insert(nums[j]);
        path.push_back(nums[j]);
        dfs(nums, path, ans, j + 1);
        path.pop_back();
      }
    }
  }
};
