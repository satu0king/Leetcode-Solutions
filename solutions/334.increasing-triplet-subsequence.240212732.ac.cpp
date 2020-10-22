
class Solution {
public:
  bool increasingTriplet(vector<int> &nums) {

    int i = 0;
    int r = nums.size() - 1;

    if (r < 2)
      return false;

    int currentSecond = INT_MAX;
    int currentFirst = nums[0];

    for (int i = 0; i <= r; i++) {

      if (nums[i] > currentSecond)
        return true;
      else if (nums[i] > currentFirst)
        currentSecond = nums[i];
      else
        currentFirst = nums[i];
    }

    return false;
  }
};
