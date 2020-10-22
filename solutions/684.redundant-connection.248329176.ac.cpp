class DSU {
public:
  int n;
  int setCount;
  vector<set<int>> _sets;
  vector<int> _setIndex;

  DSU(int n) : n(n), setCount(n) {

    for (int i = 0; i < n; i++) {
      _sets.push_back({i});
      _setIndex.push_back(i);
    }
  }

  int setIndex(int i) { return _setIndex[i]; }

  set<int> &getSet(int i) { return _sets[_setIndex[i]]; }

  int setSize(int i) { return getSet(i).size(); }

  void join(int i, int j) {

    if (setIndex(i) == setIndex(j))
      return;
    if (setSize(i) < setSize(j))
      swap(i, j);

    auto &set1 = getSet(i);
    auto &set2 = getSet(j);

    int targetSetIndex = setIndex(i);

    set1.insert(set2.begin(), set2.end());

    for (int k : set2)
      _setIndex[k] = targetSetIndex;

    setCount--;

    set2.clear();
  }
};

class Solution {

public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    DSU dsu(n + 1);

    for (auto v : edges)
      if (dsu.setIndex(v[0]) == dsu.setIndex(v[1]))
        return v;
      else
        dsu.join(v[0], v[1]);

    return {};
  }
};
