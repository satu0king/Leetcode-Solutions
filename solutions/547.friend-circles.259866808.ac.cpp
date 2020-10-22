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
  int findCircleNum(vector<vector<int>> &M) {
    int n = M.size();
    DSU dsu(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (M[i][j])
          dsu.join(i, j);
    return dsu.setCount;
  }
};
