class Solution {
public:
  bool possible(vector<int> &nums, int m, long long int mx) {
    if (*max_element(nums.begin(), nums.end()) > mx)
      return false;

    long long int sm = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      sm += nums[i];
      if (sm > mx) {
        sm = nums[i];
        m--;
      }
    }

    return m > 0;
  }

  int splitArray(vector<int> &nums, int m) {
    long long int r = accumulate(nums.begin(), nums.end(), 0L);
    int l = 0;

    int ans = 0;

    while (l <= r) {
      long long int mx = (l + r) / 2;
      bool ret = possible(nums, m, mx);
      if (ret) {
        ans = mx;
        r = mx - 1;
      } else
        l = mx + 1;
    }

    return ans;
  }
};
