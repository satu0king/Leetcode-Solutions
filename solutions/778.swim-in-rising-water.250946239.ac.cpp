class Solution {
  vector<vector<int>> grid;
  vector<vector<bool>> visited;

public:
  int swimInWater(vector<vector<int>> &grid) {
    this->grid = grid;
    int n = grid.size();
    if (!n)
      return 0;
    int m = grid[0].size();
    visited.resize(n, vector<bool>(m));

    int ans = 0;
    set<pair<int, pair<int, int>>> pq;
    pq.emplace(grid[0][0], make_pair(0, 0));

    while (pq.size()) {
      auto p = *pq.begin();
      pq.erase(pq.begin());
      int i = p.second.first;
      int j = p.second.second;
      ans = max(ans, p.first);
      if (i == n - 1 && j == m - 1)
        break;
      visited[i][j] = true;

      if (i && !visited[i - 1][j])
        pq.emplace(grid[i - 1][j], make_pair(i - 1, j));
      if (i != n - 1 && !visited[i + 1][j])
        pq.emplace(grid[i + 1][j], make_pair(i + 1, j));
      if (j && !visited[i][j - 1])
        pq.emplace(grid[i][j - 1], make_pair(i, j - 1));
      if (j != m - 1 && !visited[i][j + 1])
        pq.emplace(grid[i][j + 1], make_pair(i, j + 1));
    }

    return ans;
  }
};
