class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    int sum = 0;
    for (int &a : nums) {
      sum += a;
      a = sum;
    }
    return nums;
  }
};
