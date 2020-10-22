class NumArray {
public:
  vector<int> n;
  NumArray(vector<int> &nums) {
    n.push_back(0);
    for (auto num : nums)
      n.push_back(n.back() + num);
  }

  int sumRange(int i, int j) { return n[j + 1] - n[i]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
