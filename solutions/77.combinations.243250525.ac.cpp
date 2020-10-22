class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> path;
    f(n, k, ans, path, 1);
    return ans;
  }

  void f(int n, int k, vector<vector<int>> &ans, vector<int> &path, int i = 1) {
    if (n - i + 1 < k)
      return;
    if (k == 0) {
      ans.push_back(path);
      return;
    }

    f(n, k, ans, path, i + 1);
    path.push_back(i);
    f(n, k - 1, ans, path, i + 1);
    path.pop_back();
  }
};
