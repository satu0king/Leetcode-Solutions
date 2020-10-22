class Solution {
public:
  int getMaxLen(vector<int> &nums) {
    int positive = 0;
    int negative = -1;
    int ans = 0;
    long int c = 1;
    for (int i = 0; i < nums.size(); i++) {
      if (c == 0)
        c = 1;
      c *= nums[i];
      if (c == 0) {
        positive = -1;
        negative = -1;
      }

      if (c > 0 && positive == -1) {
        positive = i;
      }
      if (c < 0 && negative == -1) {
        negative = i;
      }

      if (c > 0 && positive != -1) {
        c = 1;
        ans = max(ans, i - positive + 1);
      } else if (c < 0 && negative != -1) {
        c = -1;
        ans = max(ans, i - negative);
      }

      if (c == 0) {
        positive = i + 1;
      }
    }
    return ans;
  }
};
