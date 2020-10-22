class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {

    unordered_map<string, vector<string>> g;
    unordered_map<string, string> names;

    unordered_set<string> visited;

    for (auto &acc : accounts) {
      int n = acc.size();
      for (int i = 1; i < n; i++) {
        names[acc[i]] = acc[0];
        if (i != 1) {
          g[acc[i]].push_back(acc[i - 1]);
          g[acc[i - 1]].push_back(acc[i]);
        }
      }
    }

    vector<vector<string>> ans;

    for (auto &p : names) {
      vector<string> path;
      string email = p.first;
      // cout<<email<<endl;
      dfs(path, g, email, visited);
      if (path.size()) {
        path.push_back(p.second);
        reverse(path.begin(), path.end());
        sort(path.begin() + 1, path.end());
        ans.push_back(path);
      }
    }

    return ans;
  }

  void dfs(vector<string> &path, unordered_map<string, vector<string>> &g,
           string &root, unordered_set<string> &visited) {
    if (visited.count(root))
      return;
    visited.insert(root);
    path.push_back(root);
    for (auto &s : g[root])
      dfs(path, g, s, visited);
  }
};
