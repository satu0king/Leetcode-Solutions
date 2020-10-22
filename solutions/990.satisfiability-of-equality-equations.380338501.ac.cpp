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
  bool equationsPossible(vector<string> &equations) {
    DSU dsu(26);

    for (string &eq : equations) {
      if (eq[1] == '!')
        continue;
      int v1 = eq[0] - 'a';
      int v2 = eq[3] - 'a';
      dsu.join(v1, v2);
    }
    for (string &eq : equations) {
      if (eq[1] == '=')
        continue;
      int v1 = eq[0] - 'a';
      int v2 = eq[3] - 'a';
      if (dsu.findSet(v1) == dsu.findSet(v2))
        return false;
    }

    return true;
  }
};
