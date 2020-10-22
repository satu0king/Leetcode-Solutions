struct DSU {
  vector<int> sets;
  vector<int> size;
  int setCount;
  DSU(int n) : sets(n), size(n, 1), setCount(n) {
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
    sets[j] = i;
    size[i] += size[j];
    return true;
  }
};

class Solution {
public:
  int largestComponentSize(vector<int> &A) {
    unordered_map<int, int> nodeIndexMap;
    int n = A.size();
    for (int i = 0; i < n; i++)
      nodeIndexMap[A[i]] = i;

    int mx = *max_element(A.begin(), A.end());
    vector<bool> visited(mx + 1);
    DSU dsu(n);

    for (int i = 2; i < mx; i++) {
      if (visited[i])
        continue;
      vector<int> sameComponent;
      for (int j = i; j <= mx; j += i) {
        visited[j] = true;
        if (nodeIndexMap.count(j))
          sameComponent.push_back(nodeIndexMap[j]);
      }
      // for(int j = 0; j < sameComponent.size() - 1; j++)
      //     dsu.join(sameComponent[j], sameComponent[j+1]);
      for (int j = 1; j < sameComponent.size(); j++)
        dsu.join(sameComponent[j], sameComponent[j - 1]);
    }
    return *max_element(dsu.size.begin(), dsu.size.end());
  }
};
