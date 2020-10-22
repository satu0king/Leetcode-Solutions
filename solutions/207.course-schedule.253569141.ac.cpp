class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

    vector<vector<int>> g(numCourses);
    for (auto v : prerequisites)
      g[v[0]].push_back(v[1]);

    vector<bool> visited(numCourses);
    vector<bool> recStack(numCourses);

    for (int i = 0; i < numCourses; i++)
      if (!visited[i] && dfs(visited, recStack, g, i))
        return false;
    return true;
  }

  bool dfs(vector<bool> &visited, vector<bool> &recStack,
           vector<vector<int>> &g, int i) {

    if (recStack[i])
      return true;
    if (visited[i])
      return false;

    visited[i] = true;
    recStack[i] = true;

    for (int j : g[i])
      if (dfs(visited, recStack, g, j))
        return true;

    recStack[i] = false;

    return false;
  }
};
