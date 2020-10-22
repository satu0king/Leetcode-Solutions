struct DSU {
  vector<int> sets;
  vector<int> size;
  int setCount;
  DSU(int n) : sets(n), size(n), setCount(n) {
    for (int i = 0; i < n; i++)
      sets[i] = i;
  }

  int findSet(int i) {
    if (sets[i] == i)
      return i;
    return sets[i] = findSet(sets[i]);
  }

  bool join(int i, int j) {
    i = findSet(i);
    j = findSet(j);
    if (i == j)
      return false;
    setCount--;
    if (size[i] < size[j])
      swap(i, j);
    sets[j] = sets[i];
    size[i] += size[j];
    return true;
  }
};

class Solution {
public:
  int regionsBySlashes(vector<string> &grid) {
    int n = grid.size();
    DSU dsu(4 * n * n);

    auto id = [n](int i, int j, int k) { return 4 * (i * n + j) + k; };

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n - 1; j++)
        dsu.join(id(i, j, 2), id(i, j + 1, 0));

    for (int i = 0; i < n - 1; i++)
      for (int j = 0; j < n; j++)
        dsu.join(id(i, j, 3), id(i + 1, j, 1));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '/') {
          dsu.join(id(i, j, 2), id(i, j, 3));
          dsu.join(id(i, j, 0), id(i, j, 1));
        } else if (grid[i][j] == '\\') {
          dsu.join(id(i, j, 1), id(i, j, 2));
          dsu.join(id(i, j, 0), id(i, j, 3));
        } else {
          dsu.join(id(i, j, 0), id(i, j, 1));
          dsu.join(id(i, j, 0), id(i, j, 2));
          dsu.join(id(i, j, 0), id(i, j, 3));
        }
      }

    return dsu.setCount;
  }
};
