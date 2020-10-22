struct DSU {
  int n;
  int setCount;
  vector<int> parent;
  vector<int> size;
  DSU(int n) : parent(n), size(n, 1), setCount(n) {
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int find(int i) {
    if (parent[i] == i)
      return i;
    return parent[i] = find(parent[i]);
  }

  bool join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j)
      return false;

    if (size[j] > size[i])
      swap(j, i);

    parent[j] = i;
    size[i] += size[j];

    setCount--;

    return true;
  }
};

class Solution {
public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    DSU dsu(n);

    int c = 0;

    if (connections.size() < n - 1)
      return -1;

    for (auto &v : connections)
      if (dsu.join(v[0], v[1]))
        c++;

    return n - 1 - c;
  }
};
