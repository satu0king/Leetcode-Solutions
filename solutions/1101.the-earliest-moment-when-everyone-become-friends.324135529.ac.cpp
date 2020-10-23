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

  void join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j)
      return;

    if (size[j] > size[i])
      swap(j, i);

    parent[j] = i;
    size[i] += size[j];

    setCount--;
  }
};

class Solution {
public:
  int earliestAcq(vector<vector<int>> &logs, int N) {
    sort(logs.begin(), logs.end());

    DSU dsu(N);

    for (auto &log : logs) {
      dsu.join(log[1], log[2]);
      if (dsu.setCount == 1)
        return log[0];
    }

    return -1;
  }
};
