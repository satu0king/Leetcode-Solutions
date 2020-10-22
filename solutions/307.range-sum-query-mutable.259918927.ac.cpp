struct bit { // use 0 based indices!!!
  vector<int> a;
  int n;
  bit(int n) : a(n + 1), n(n + 1){};
  void update(int i, int val) {
    for (i++; i < n; i += i & (-i))
      a[i] += val;
  }

  int query(int j) {
    int ans = 0;
    for (j++; j; j -= j & (-j))
      ans += a[j];
    return ans;
  }

  void assign(int i, int val) { update(i, val - query(i, i)); }

  int query(int i, int j) { return query(j) - query(i - 1); }
};

class NumArray {
  bit b1;

public:
  NumArray(vector<int> &nums) : b1(nums.size()) {
    for (int i = 0; i < nums.size(); i++)
      b1.update(i, nums[i]);
  }

  void update(int i, int val) { b1.assign(i, val); }

  int sumRange(int i, int j) { return b1.query(i, j); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
