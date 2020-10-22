
struct DSU {
  int n;

  vector<int> parentSet;
  vector<int> setSize;

  DSU(int n) : n(n), parentSet(n), setSize(n, 1) {
    for (int i = 0; i < n; i++)
      parentSet[i] = i;
  }

  int getSet(int i) {
    if (parentSet[i] == i)
      return i;
    return parentSet[i] = getSet(parentSet[i]);
  }

  void join(int i, int j) {
    i = getSet(i);
    j = getSet(j);
    if (i == j)
      return;
    if (setSize[i] < setSize[j])
      swap(i, j);

    setSize[i] += setSize[j];
    parentSet[j] = i;
  }

  unordered_map<int, vector<int>> getSets() {
    unordered_map<int, vector<int>> ans;
    for (int i = 0; i < n; i++)
      ans[getSet(i)].push_back(i);
    return ans;
  }
};

class Solution {
public:
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    int n = s.size();
    DSU dsu(n);
    for (auto p : pairs)
      dsu.join(p[0], p[1]);

    for (auto p : dsu.getSets()) {
      auto &v = p.second;
      sort(v.begin(), v.end());
      string t;
      for (int j : v)
        t += s[j];
      sort(t.begin(), t.end());
      for (int j = 0; j < v.size(); j++)
        s[v[j]] = t[j];
    }

    return s;
  }
};
