class Solution {

  vector<vector<int>> borders;
  vector<vector<int>> grid;

public:
  vector<vector<int>> colorBorder(vector<vector<int>> &_grid, int r0, int c0,
                                  int color) {

    grid = _grid;
    int prevColor = grid[r0][c0];
    findBorders(r0, c0, prevColor);

    for (auto v : borders)
      _grid[v[0]][v[1]] = color;

    return _grid;
  }

  bool findBorders(int i, int j, int color) {

    int n = grid.size();

    int m = grid[0].size();

    if (i < 0 || j < 0 || i >= n || j >= m)
      return true;

    if (grid[i][j] != color)
      return grid[i][j] != 0;

    grid[i][j] = 0;
    bool isBorder = findBorders(i - 1, j, color);
    isBorder |= findBorders(i + 1, j, color);
    isBorder |= findBorders(i, j + 1, color);
    isBorder |= findBorders(i, j - 1, color);

    if (isBorder)
      borders.push_back({i, j});

    return false;
  }
};
