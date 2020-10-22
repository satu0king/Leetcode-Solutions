class Solution {

  unordered_map<string, vector<int>> numerators;

public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    int n = equations.size();

    for (int i = 0; i < n; i++) {
      if (values[i] != 0) {
        equations.push_back({equations[i][1], equations[i][0]});
        values.push_back(1 / values[i]);
      }
    }

    n = equations.size();
    for (int i = 0; i < n; i++) {
      string num = equations[i][0];
      string den = equations[i][1];
      numerators[num].push_back(i);
    }
    vector<double> res;
    for (auto q : queries) {
      double r = -1;
      vector<bool> visited(n);
      for (int j : numerators[q[0]]) {
        if (!visited[j])
          r = dfs(visited, equations, values, j, q[1]);
        if (j != -1)
          break;
      }
      res.push_back(r);
    }

    return res;
  }

  double dfs(vector<bool> &visited, vector<vector<string>> &equations,
             vector<double> &values, int i, string &den) {
    visited[i] = true;
    if (equations[i][1] == den)
      return values[i];

    for (int j : numerators[equations[i][1]]) {
      if (!visited[j]) {
        double r = dfs(visited, equations, values, j, den);
        if (r != -1)
          return r * values[i];
      }
    }

    return -1;
  }
};
