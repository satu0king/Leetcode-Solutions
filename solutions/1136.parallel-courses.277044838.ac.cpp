class Solution {

public:
  int minimumSemesters(int N, vector<vector<int>> &relations) {
    vector<int> state(N);
    vector<int> ans(N, 1);
    vector<vector<int>> graph(N);

    for (auto edge : relations)
      graph[edge[0] - 1].push_back(edge[1] - 1);

    for (int i = 0; i < N; i++)
      if (dfs(i, state, ans, graph))
        return -1;

    return *max_element(ans.begin(), ans.end());
  }

  bool dfs(int i, vector<int> &state, vector<int> &ans,
           vector<vector<int>> &graph) {
    if (state[i] == 2)
      return false;
    if (state[i] == 1)
      return true;

    state[i]++;

    for (int j : graph[i]) {
      if (dfs(j, state, ans, graph))
        return true;
      ans[i] = max(ans[i], ans[j] + 1);
    }

    state[i]++;

    return false;
  }
};
