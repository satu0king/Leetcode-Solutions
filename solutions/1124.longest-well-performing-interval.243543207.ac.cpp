class Solution {
public:
  int longestWPI(vector<int> &hours) {
    int mx = 0;
    int k = 0;
    int current = 0;

    int n = hours.size();

    for (int i = 0; i < n; i++)
      if (hours[i] > 8)
        hours[i] = 1;
      else
        hours[i] = -1;

    for (int i = 1; i < n; i++)
      hours[i] += hours[i - 1];

    vector<int> maxSum(n, hours[n - 1]);

    for (int i = n - 2; i >= 0; i--)
      maxSum[i] = max(maxSum[i + 1], hours[i]);

    for (int i = 0; i < n; i++) {
      int t = i ? hours[i - 1] : 0;
      int j = bsearch(maxSum, i, n - 1, t + 1);
      if (~j)
        mx = max(mx, j - i + 1);
    }

    return mx;
  }

  int bsearch(vector<int> &a, int l, int r, int v) {
    int ans = -1;

    while (l <= r) {
      int mid = (l + r) / 2;
      if (a[mid] >= v) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }

    return ans;
  }
};
