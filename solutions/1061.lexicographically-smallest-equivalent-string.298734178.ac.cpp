struct DSU {
  vector<int> parent;
  DSU(int n) : parent(n) {
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int getSet(int i) {
    if (parent[i] == i)
      return i;
    return parent[i] = getSet(parent[i]);
  }

  void join(int a, int b) {

    a = getSet(a);
    b = getSet(b);

    if (a > b)
      swap(a, b);

    parent[b] = a;
  }
};

class Solution {
public:
  string smallestEquivalentString(string A, string B, string S) {
    DSU dsu(256);

    for (int i = 0; i < A.size(); i++)
      dsu.join(A[i], B[i]);

    for (char &c : S)
      c = dsu.getSet(c);

    return S;
  }
};
