class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
    if (S == T)
      return 0;
    int ans = 0;
    unordered_set<int> visited;
    unordered_map<int, vector<int>> g;
    for (int i = 0; i < routes.size(); i++)
      for (int j : routes[i])
        g[j].push_back(i);

    queue<int> q;
    q.push(S);
    while (q.size()) {
      int t = q.size();
      ans++;
      while (t--) {
        int i = q.front();
        q.pop();
        for (int r : g[i])
          if (!visited.count(r)) {
            visited.insert(r);
            for (int j : routes[r]) {
              if (j == T)
                return ans;
              q.push(j);
            }
          }
      }
    }

    return -1;
  }
};
