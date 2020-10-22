class Solution {
public:
  int snakesAndLadders(vector<vector<int>> &board) {
    int length = board.size();
    int N = length * length;
    vector<vector<int>> graph(N);
    for (int i = 0; i < N; i++) {
      int t = min(N, i + 7);
      for (int j = i + 1; j < t; j++) {
        auto p = f(j, length);
        int x = p.first;
        int y = p.second;
        if (~board[x][y]) {
          graph[i].push_back(board[x][y] - 1);
        } else {
          graph[i].push_back(j);
        }
      }
    }
    queue<int> q;
    vector<bool> visited(N);
    int ans = 0;
    visited[0] = true;
    q.push(0);
    while (q.size()) {
      int t = q.size();
      ans++;
      while (t--) {
        int i = q.front();
        q.pop();
        for (int j : graph[i]) {
          if (j == N - 1) {
            return ans;
          }
          if (visited[j])
            continue;
          visited[j] = true;
          q.push(j);
        }
      }
    }
    return -1;
  }

  pair<int, int> f(int x, int n) {
    int row = x / n;
    int col = x % n;
    if (row % 2)
      col = n - col - 1;
    return {n - row - 1, col};
  }
};
