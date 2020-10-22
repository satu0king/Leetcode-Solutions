class Solution {
  vector<int> dp;
  int n;

public:
  int removeBoxes(vector<int> &boxes) {
    dp.resize(1000005, -1);
    n = boxes.size();
    return f(0, n - 1, 0, boxes);
  }

  int f(int l, int r, int k, vector<int> &boxes) {
    if (l > r)
      return 0;
    int key = l + (r + 1) * 100 + (k + 1) * 100 * 100;
    if (~dp[key])
      return dp[key];
    int ans = 0;
    k++;
    while (l < r && boxes[l] == boxes[l + 1]) {
      k++;
      l++;
    }

    ans = f(l + 1, r, 0, boxes) + k * k;

    for (int i = l + 1; i <= r; i++) {
      if (boxes[i] == boxes[l])
        ans = max(ans, f(l + 1, i - 1, 0, boxes) + f(i, r, k, boxes));
    }

    dp[key] = ans;
    return ans;
  }
};
