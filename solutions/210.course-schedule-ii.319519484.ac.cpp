class Solution {
public:
  vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
    vector<vector<int>> g(n);
    for (auto &v : prerequisites)
      g[v[0]].push_back(v[1]);

    // 0 -> not visited
    // 1 -> visited in Recursion Stack
    // 2 -> visited and out of Recursion Stack
    vector<int> state(n);

    vector<int> ans;

    for (int i = 0; i < n; i++)
      if (!state[i] && !dfs(g, state, ans, i))
        return vector<int>{};

    return ans;
  }

  bool dfs(vector<vector<int>> &g, vector<int> &state, vector<int> &ans,
           int i) {
    if (state[i] == 2)
      return true;
    if (state[i] == 1)
      return false;

    state[i]++;

    for (int j : g[i])
      if (!dfs(g, state, ans, j))
        return false;

    ans.push_back(i);
    state[i]++;

    return true;
  }
};
