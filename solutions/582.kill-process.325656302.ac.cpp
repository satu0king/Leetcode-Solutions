class Solution {
public:
  vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
    unordered_map<int, vector<int>> g;
    for (int i = 0; i < pid.size(); i++)
      g[ppid[i]].push_back(pid[i]);
    vector<int> pids;
    dfs(g, kill, pids);
    return pids;
  }

  void dfs(unordered_map<int, vector<int>> &g, int i, vector<int> &pids) {
    pids.push_back(i);
    for (int v : g[i])
      dfs(g, v, pids);
  }
};
