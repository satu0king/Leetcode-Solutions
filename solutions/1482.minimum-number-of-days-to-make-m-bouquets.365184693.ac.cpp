class Solution {
  int f(vector<int> bloomDay, int d, int k) {
    int c = 0;
    int count = 0;
    for (int a : bloomDay) {
      if (a <= d)
        count++;
      else
        count = 0;
      if (count == k) {
        count = 0;
        c++;
      }
    }
    return c;
  }

public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    int l = 0;
    int r = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    while (l <= r) {
      int c = (l + r) / 2;
      if (f(bloomDay, c, k) >= m) {
        ans = c;
        r = c - 1;
      } else {
        l = c + 1;
      }
    }
    return ans;
  }
};
