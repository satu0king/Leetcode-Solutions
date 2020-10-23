struct Point {
  int d;
  int x;
  int y;
  int prevX;
  int prevY;
  char c;
  Point(int x = 0, int y = 0, int d = INT_MAX, char c = 's', int prevX = -1,
        int prevY = -1)
      : x(x), y(y), d(d), prevX(prevX), prevY(prevY), c(c) {}

  bool operator<(const Point &other) const {
    if (d != other.d)
      return d < other.d;
    return c < other.c;
  }
};

class Solution {

public:
  string findShortestWay(vector<vector<int>> &maze, vector<int> &ball,
                         vector<int> &hole) {
    vector<tuple<int, int, char>> directions = {
        {0, 1, 'r'}, {0, -1, 'l'}, {1, 0, 'd'}, {-1, 0, 'u'}};
    int n = maze.size();
    int m = maze[0].size();

    multiset<Point> q;
    q.insert(Point(ball[0], ball[1], 0));

    vector<vector<Point>> visited(n, vector<Point>(m));

    string minString = "impossible";
    int minDistance = INT_MAX;

    while (q.size()) {
      auto point = *q.begin();
      q.erase(q.begin());

      if (point.d > visited[point.x][point.y].d)
        continue;
      // if(point.d > minDistance) continue;
      visited[point.x][point.y] = point;

      for (auto [dx, dy, dir] : directions) {
        int newX = point.x;
        int newY = point.y;

        int newD = point.d;
        while (newX >= 0 && newY >= 0 && newX < n && newY < m &&
               !maze[newX][newY]) {
          if (newX == hole[0] && newY == hole[1] && newD <= minDistance) {
            string path = "";
            path += dir;

            auto temp = point;
            while (temp.d) {
              path += temp.c;
              temp = visited[temp.prevX][temp.prevY];
            }
            reverse(path.begin(), path.end());
            // cout << path << " " << newD <<endl;
            if (newD < minDistance)
              minString = path;
            else
              minString = min(minString, path);
            minDistance = newD;
          }
          newX += dx;
          newY += dy;
          newD++;
        }
        newD--;

        newX -= dx;
        newY -= dy;

        Point pnew(newX, newY, newD, dir, point.x, point.y);

        if (visited[newX][newY].d > pnew.d) {
          q.insert(pnew);
        }
      }
    }

    return minString;
  }
};
