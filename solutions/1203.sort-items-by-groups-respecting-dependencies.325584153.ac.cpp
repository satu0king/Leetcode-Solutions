class Solution {
public:
  vector<int> sortItems(int n, int m, vector<int> &group,
                        vector<vector<int>> &beforeItems) {
    vector<unordered_set<int>> graph(n + 2 * m);

    for (int i = 0; i < n; i++) {
      if (~group[i]) {
        graph[i].insert(n + group[i]);
        graph[n + m + group[i]].insert(i);
      }
      for (auto j : beforeItems[i])
        if (~group[i] && group[i] == group[j])
          graph[i].insert(j);
        else {

          int jg = ~group[j] ? group[j] + n + m : j;
          int ig = ~group[i] ? group[i] + n : i;

          graph[ig].insert(jg);
        }
    }

    vector<int> order;
    vector<int> stackState(n + 2 * m);

    for (int i = n + 2 * m - 1; i >= 0; i--)
      if (!dfs(graph, order, stackState, i))
        return {};

    vector<int> ans(n);
    copy_if(order.begin(), order.end(), ans.begin(),
            [&n](int i) { return i < n; });

    return ans;
  }

  bool dfs(vector<unordered_set<int>> &graph, vector<int> &order,
           vector<int> &stackState, int i) {
    if (stackState[i])
      return stackState[i] == 2;
    stackState[i] = 1;

    for (int v : graph[i])
      if (!dfs(graph, order, stackState, v))
        return false;

    order.push_back(i);
    stackState[i] = 2;
    return true;
  }
};
