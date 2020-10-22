class Solution {
  vector<int> ans;
  vector<int> count;
  vector<vector<int>> g;

public:
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
    ans.resize(N);
    count.resize(N);
    g.resize(N);
    for (auto &e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    dfs(0);
    dfs1(0);
    return ans;
  }

  void dfs(int i, int parent = -1) {
    count[i]++;
    for (int j : g[i]) {
      if (j == parent)
        continue;
      dfs(j, i);
      count[i] += count[j];
      ans[i] += ans[j] + count[j];
    }
  }

  void dfs1(int i, int parent = -1) {
    count[i]++;
    for (int j : g[i]) {
      if (j == parent)
        continue;
      ans[j] += (ans[i] - ans[j] - count[j]) + (ans.size() - count[j]);
      dfs1(j, i);
    }
  }
};
