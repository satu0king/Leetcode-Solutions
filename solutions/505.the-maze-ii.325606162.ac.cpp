class Solution {
public:
  int shortestDistance(vector<vector<int>> &maze, vector<int> &start,
                       vector<int> &destination) {
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n = maze.size();
    int m = maze[0].size();

    priority_queue<tuple<int, int, int>> q;
    q.emplace(0, start[0], start[1]);

    vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
    visited[start[0]][start[1]] = true;

    while (q.size()) {
      auto [d, x, y] = q.top();
      q.pop();

      if (-d > visited[x][y])
        continue;
      visited[x][y] = -d;

      if (x == destination[0] && y == destination[1])
        return -d;

      for (auto [dx, dy] : directions) {
        int newX = x;
        int newY = y;

        int newD = -d;
        while (newX >= 0 && newY >= 0 && newX < n && newY < m &&
               !maze[newX][newY]) {
          newX += dx;
          newY += dy;
          newD++;
        }
        newD--;

        if (visited[newX - dx][newY - dy] > newD) {
          visited[newX - dx][newY - dy] = newD;
          q.emplace(-newD, newX - dx, newY - dy);
        }
      }
    }

    return -1;
  }
};
