class Solution {
public:
  bool hasPath(vector<vector<int>> &maze, vector<int> &start,
               vector<int> &destination) {
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n = maze.size();
    int m = maze[0].size();

    queue<pair<int, int>> q;
    q.emplace(start[0], start[1]);

    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[start[0]][start[1]] = true;

    while (q.size()) {
      auto p = q.front();
      q.pop();
      int x = p.first;
      int y = p.second;
      if (x == destination[0] && y == destination[1])
        return true;

      for (auto [dx, dy] : directions) {
        int newX = x;
        int newY = y;

        while (newX >= 0 && newY >= 0 && newX < n && newY < m &&
               !maze[newX][newY]) {
          newX += dx;
          newY += dy;
        }

        if (!visited[newX - dx][newY - dy]) {
          visited[newX - dx][newY - dy] = true;
          q.emplace(newX - dx, newY - dy);
        }
      }
    }

    return false;
  }
};
