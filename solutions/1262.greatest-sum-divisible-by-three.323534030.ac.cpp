class Solution {
public:
  int maxSumDivThree(vector<int> &nums) {
    int sum = 0;
    int leftOne = 20000;
    int leftTwo = 20000;

    for (int n : nums) {
      sum += n;
      if (n % 3 == 1) {
        leftTwo = min(leftTwo, leftOne + n);
        leftOne = min(leftOne, n);
      } else if (n % 3 == 2) {
        leftOne = min(leftOne, leftTwo + n);
        leftTwo = min(leftTwo, n);
      }
    }

    if (sum % 3 == 1)
      return sum - leftOne;
    if (sum % 3 == 2)
      return sum - leftTwo;

    return sum;
  }
};
