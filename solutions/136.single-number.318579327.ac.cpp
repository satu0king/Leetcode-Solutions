class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int x = 0;
    for (int n : nums)
      x ^= n;
    return x;
  }
};
