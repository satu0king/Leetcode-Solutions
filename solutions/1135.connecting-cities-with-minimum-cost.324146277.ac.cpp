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
  int minimumCost(int N, vector<vector<int>> &connections) {
    auto cmp = [](const vector<int> &v1, const vector<int> &v2) -> bool {
      return v1[2] < v2[2];
    };
    sort(begin(connections), end(connections), cmp);

    int ans = 0;
    DSU dsu(N);

    for (auto &c : connections) {
      if (dsu.join(c[0] - 1, c[1] - 1))
        ans += c[2];

      if (dsu.setCount == 1)
        return ans;
    }

    return -1;
  }
};
