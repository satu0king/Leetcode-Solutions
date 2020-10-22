class Solution {
  vector<vector<int>> ans;
  vector<int> path;
  vector<bool> visited;

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    visited = vector<bool>(n);
    dfs(nums);
    return ans;
  }

  void dfs(vector<int> &nums) {
    if (path.size() == nums.size()) {
      ans.push_back(path);
      return;
    }
    int prev = INT_MIN;
    for (int j = 0; j < nums.size(); j++) {
      if (!visited[j] && nums[j] != prev) {
        visited[j] = true;
        path.push_back(nums[j]);
        prev = nums[j];
        dfs(nums);
        path.pop_back();
        visited[j] = false;
      }
    }
  }
};
