struct bit {
  int n;
  vector<int> tree;
  bit(int n) : n(n), tree(n + 1) {}

  void update(int i, int v) {
    for (i++; i <= n; i += i & (-i))
      tree[i] += v;
  }
  int query(int i) {
    int ans = 0;
    for (i++; i; i -= i & (-i))
      ans += tree[i];
    return ans;
  }
  int query(int l, int r) { return query(r) - query(l - 1); }
};

class Solution {
public:
  vector<int> processQueries(vector<int> &queries, int m) {
    vector<int> ans;
    int n = queries.size();
    bit bit1(m + n);

    vector<int> map(m + 1);
    for (int i = 0; i < m; i++) {
      bit1.update(i + n, 1);
      map[i + 1] = i + n;
    }

    for (int &q : queries) {
      int i = map[q];
      bit1.update(i, -1);
      ans.push_back(bit1.query(i));
      n--;
      map[q] = n;
      bit1.update(n, 1);
    }

    return ans;
  }
};
