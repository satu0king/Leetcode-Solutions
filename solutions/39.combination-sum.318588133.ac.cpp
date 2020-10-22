class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> path;
    f(ans, path, candidates, target);
    return ans;
  }

  void f(vector<vector<int>> &ans, vector<int> &path, vector<int> &candidates,
         int target, int i = 0) {

    if (target == 0) {
      ans.push_back(path);
      return;
    }

    if (target < 0)
      return;
    if (i >= candidates.size())
      return;

    path.push_back(candidates[i]);
    f(ans, path, candidates, target - candidates[i], i);
    path.pop_back();

    f(ans, path, candidates, target, i + 1);
  }
};
