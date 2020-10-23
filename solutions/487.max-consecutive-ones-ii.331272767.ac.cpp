class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int ans = 0;
    int ones = 0;
    int onesAndZero = 0;

    for (int a : nums) {
      if (a) {
        ones++;
        onesAndZero++;
      } else {
        onesAndZero = ones + 1;
        ones = 0;
      }
      ans = max(ans, onesAndZero);
    }

    return ans;
  }
};
