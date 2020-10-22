struct DSU {
  vector<int> parent;
  vector<int> size;
  int setCount;
  DSU(int n) : size(n, 1), parent(n), setCount(n) {
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
    if (size[i] < size[j])
      swap(i, j);
    size[i] += size[j];
    parent[j] = i;
    setCount--;
    return true;
  }
};

class Solution {
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
    DSU dsu1(n);
    DSU dsu2(n);
    int ans = 0;
    for (auto &e : edges) {
      int type = e[0];
      int u = e[1] - 1;
      int v = e[2] - 1;
      if (type == 3) {
        if (dsu1.join(u, v))
          dsu2.join(u, v);
        else
          ans++;
      }
    }
    for (auto &e : edges) {
      int type = e[0];
      int u = e[1] - 1;
      int v = e[2] - 1;
      if (type == 2) {
        if (!dsu2.join(u, v))
          ans++;
      } else if (type == 1) {
        if (!dsu1.join(u, v))
          ans++;
      }
    }
    if (dsu1.setCount != 1 || dsu2.setCount != 1)
      return -1;
    return ans;
  }
};
