
int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};

class Solution {
public:
  int cutOffTree(vector<vector<int>> &forest) {
    int n = forest.size();
    if (n == 0)
      return 0;
    int m = forest[0].size();
    vector<vector<int>> trees;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (forest[i][j] > 1)
          trees.push_back({forest[i][j], i, j});
    sort(trees.begin(), trees.end());

    int ans = 0;

    int currentI = 0;
    int currentJ = 0;

    for (auto tree : trees) {
      int i = tree[1];
      int j = tree[2];

      int t = dist(forest, currentI, currentJ, i, j);
      if (~t)
        ans += t;
      else
        return -1;

      currentI = i;
      currentJ = j;
    }

    return ans;
  }

  int dist(vector<vector<int>> &forest, int i, int j, int x, int y) {
    int n = forest.size();
    int m = forest[0].size();

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m));

    visited[i][j] = true;
    q.emplace(i, j);

    int ans = 0;

    while (q.size()) {
      int t = q.size();
      while (t--) {
        auto p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        if (i == x && j == y)
          return ans;

        for (int k = 0; k < 4; k++) {
          int ii = i + xx[k];
          int jj = j + yy[k];
          if (ii >= 0 && jj >= 0 && ii < n && jj < m) {
            if (!visited[ii][jj] && forest[ii][jj]) {
              visited[ii][jj] = true;
              q.emplace(ii, jj);
            }
          }
        }
      }
      ans++;
    }

    return -1;
  }
};
