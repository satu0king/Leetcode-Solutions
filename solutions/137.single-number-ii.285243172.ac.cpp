class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
      int s = 0;
      int mask = (1 << i);
      for (auto n : nums)
        if (n & mask)
          s++;

      s %= 3;
      if (s)
        ans = ans | mask;
    }
    return ans;
  }
};
