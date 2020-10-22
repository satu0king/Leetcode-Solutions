class Solution {
public:
  vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
    vector<vector<int>> g(n);
    for (auto &v : edges) {
      g[v[0]].push_back(v[1]);
      g[v[1]].push_back(v[0]);
    }

    vector<int> ans(n);
    dfs(ans, g, labels);
    return ans;
  }

  vector<int> dfs(vector<int> &ans, vector<vector<int>> &g, string &labels,
                  int i = 0, int parent = -1) {
    vector<int> temp(26);
    for (int j : g[i]) {
      if (j == parent)
        continue;
      auto temp2 = dfs(ans, g, labels, j, i);
      for (int i = 0; i < 26; i++)
        temp[i] += temp2[i];
    }

    ans[i] = ++temp[labels[i] - 'a'];
    return temp;
  }
};
