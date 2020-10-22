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
  int numSimilarGroups(vector<string> &A) {
    int n = A.size();
    DSU dsu(n);
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if (dsu.findSet(i) == dsu.findSet(j))
          continue;
        if (isSimilar(A[i], A[j]))
          dsu.join(i, j);
      }
    return dsu.setCount;
  }

  bool isSimilar(string &s1, string &s2) {
    int n = s1.size();
    int diffIndex[3];
    int dif = 0;
    for (int i = 0; i < n && dif <= 2; i++)
      if (s1[i] != s2[i])
        diffIndex[dif++] = i;

    if (dif == 0)
      return true;
    if (dif != 2)
      return false;

    int i = diffIndex[0];
    int j = diffIndex[1];

    if (s1[i] != s2[j])
      return false;
    if (s1[j] != s2[i])
      return false;

    return true;
  }
};
