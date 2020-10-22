class Solution {
  unordered_set<int> v1;
  unordered_set<int> v2;
  unordered_set<int> v3;
  vector<string> path;

  int n;
  vector<vector<string>> ans;

public:
  vector<vector<string>> solveNQueens(int n) {
    this->n = n;

    string t = "";
    for (int i = 0; i < n; i++)
      t += '.';
    path.resize(n, t);
    f();
    return ans;
  }

  void f(int i = 0) {
    if (i == n) {
      ans.push_back(path);
      return;
    }

    for (int j = 0; j < n; j++) {
      if (!v1.count(j) && !v2.count(i + j) && !v3.count(i - j)) {
        v1.insert(j);
        v2.insert(i + j);
        v3.insert(i - j);
        path[i][j] = 'Q';
        f(i + 1);
        path[i][j] = '.';
        v1.erase(j);
        v2.erase(i + j);
        v3.erase(i - j);
      }
    }
  }
};
