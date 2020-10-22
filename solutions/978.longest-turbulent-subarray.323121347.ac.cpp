class Solution {
public:
  int maxTurbulenceSize(vector<int> &A) {
    int n = A.size();
    int ans = 1;

    int dp1 = 1;
    int dp2 = 1;

    for (int i = 1; i < n; i++) {
      if (A[i] > A[i - 1]) {
        dp1 = dp2 + 1;
        dp2 = 1;
        ans = max(dp1, ans);
      } else if (A[i] < A[i - 1]) {
        dp2 = dp1 + 1;
        dp1 = 1;
        ans = max(dp2, ans);
      } else {
        dp1 = 1;
        dp2 = 1;
      }
    }

    return ans;
  }
};
