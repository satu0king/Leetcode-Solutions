class BIT {
  vector<int> bit;
  int N;

public:
  BIT(int n) {
    N = n;
    bit.resize(n + 1);
  }
  void update(int val, int index) {
    if (index > N)
      return;
    while (index <= N) {
      bit[index] += val;
      index += (index & (-index));
    }
  }
  int query(int index) {
    int query_ans = 0;
    while (index > 0) {
      query_ans += bit[index];
      index -= (index & (-index));
    }
    return query_ans;
  }
};
class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    int n = nums.size();
    BIT bit(n);
    map<int, int> ma;
    for (auto &e : nums)
      ma[e] = 0;
    int ind = 1;
    for (auto &e : ma)
      e.second = ind++;
    vector<int> counts(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1)
        counts[i] = 0;
      else
        counts[i] = bit.query(ma[nums[i]] - 1);
      bit.update(1, ma[nums[i]]);
    }
    return counts;
  }
};
