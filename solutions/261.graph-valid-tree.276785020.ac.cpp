struct DSU {
  int n;
  int setCount;
  vector<int> parent;
  vector<int> size;

  DSU(int n) : n(n), size(n, 1), parent(n), setCount(n) {
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int getSet(int i) {
    if (parent[i] == i)
      return i;
    return parent[i] = getSet(parent[i]);
  }

  bool join(int i, int j) {
    i = getSet(i);
    j = getSet(j);

    if (i == j)
      return false;
    setCount--;

    if (size[i] < size[j])
      swap(i, j);
    parent[j] = i;
    size[i] += size[j];
    return true;
  }
};

class Solution {
public:
  bool validTree(int n, vector<vector<int>> &edges) {
    DSU dsu(n);
    for (auto e : edges)
      if (!dsu.join(e[0], e[1]))
        return false;
    return dsu.setCount == 1;
  }
};
