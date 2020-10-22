class Solution {

  bool f(vector<vector<int>> &graph, int i, vector<int> &safe,
         vector<bool> &inStack) {

    if (~safe[i])
      return safe[i];

    if (inStack[i]) {
      safe[i] = 0;
      return 0;
    }

    inStack[i] = true;

    if (graph[i].size() == 0) {
      safe[i] = 1;
      return true;
    }

    for (int j : graph[i])
      if (!f(graph, j, safe, inStack)) {
        safe[i] = 0;
        return 0;
      }

    safe[i] = 1;
    return 1;
  }

public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> safe(n, -1);

    vector<bool> inStack(n);
    for (int i = 0; i < n; i++)
      if (safe[i] == -1) {
        f(graph, i, safe, inStack);
      }

    vector<int> ans;
    for (int i = 0; i < n; i++)
      if (safe[i])
        ans.push_back(i);
    return ans;
  }
};
