struct bit { // use 0 based indices!!!
  int n;
  vector<int> tree;
  bit(int n) : n(n), tree(n + 1) {}
  int query(int l, int r) { return query(r) - query(l - 1); }
  int query(int r) {
    int ans = 0;
    for (r++; r; r -= r & (-r))
      ans += tree[r];
    return ans;
  }
  void update(int i, int v) {
    for (i++; i <= n; i += i & (-i))
      tree[i] += v;
  }
  void assign(int i, int v) { update(i, v - query(i, i)); }
};

class Solution {
public:
  int numTeams(vector<int> &rating) {
    int ans = f(rating);
    reverse(rating.begin(), rating.end());
    return ans + f(rating);
  }
  int f(vector<int> &rating) {
    int n = rating.size();
    bit bit1(100001);
    bit bit2(100001);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int temp = bit1.query(0, rating[i] - 1);
      int temp2 = bit2.query(0, rating[i] - 1);
      bit1.update(rating[i], 1);
      bit2.update(rating[i], temp);
      ans += temp2;
    }
    return ans;
  }
};
