class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    long long int x = 0;
    for (int n : nums)
      x ^= n;
    long long i = x & (-x);
    int y = 0;
    for (int n : nums)
      if (n & i)
        y ^= n;
    return {y, x ^ y};
  }
};
