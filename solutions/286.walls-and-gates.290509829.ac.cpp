int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class Solution {
public:
  void wallsAndGates(vector<vector<int>> &rooms) {

    int n = rooms.size();
    if (!n)
      return;
    int m = rooms[0].size();

    int INF = 2147483647;
    queue<pair<int, int>> q;

    int dist = 1;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (rooms[i][j] == 0)
          q.emplace(i, j);
      }

    while (q.size()) {
      int _t = q.size();
      while (_t--) {
        auto p = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
          int i = p.first + dx[k];
          int j = p.second + dy[k];
          if (i >= 0 && j >= 0 && i < n && j < m && rooms[i][j] == INF) {
            rooms[i][j] = dist;
            q.emplace(i, j);
          }
        }
      }
      dist++;
    }
  }
};
