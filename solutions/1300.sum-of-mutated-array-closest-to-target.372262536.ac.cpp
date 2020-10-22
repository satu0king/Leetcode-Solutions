class Solution {
public:
  int findBestValue(vector<int> &arr, int target) {
    int l = 0;
    int r = *max_element(arr.begin(), arr.end());
    int difference = INT_MAX;
    int ans = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      int s = f(arr, m);
      int score = abs(f(arr, m) - target);
      if (score < difference) {
        difference = score;
        ans = m;
      } else if (score == difference) {
        ans = min(m, ans);
      }
      if (s >= target) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }

  int f(vector<int> &arr, int c) {
    int s = 0;
    for (int a : arr)
      s += min(a, c);
    return s;
  }
};
