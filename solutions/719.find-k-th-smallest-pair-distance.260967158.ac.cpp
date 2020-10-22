class Solution {
public:
  int smallestDistancePair(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int l = 0;
    int r = nums[n - 1] - nums[0];
    int ans = -1;
    while (l < r) {
      int m = (l + r) / 2;
      int count = 0;
      int i = 0;
      int j = 0;
      while (j < n) {
        while (nums[j] - nums[i] > m)
          i++;
        count += j - i;
        j++;
      }

      if (count >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
