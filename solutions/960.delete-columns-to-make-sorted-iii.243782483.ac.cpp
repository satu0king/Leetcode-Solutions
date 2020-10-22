class Solution {
public:
  int minDeletionSize(vector<string> &A) {
    int n = A.size();
    if (!n)
      return 0;
    int w = A[0].size();
    if (!w)
      return 0;

    vector<int> dp(w, 1);

    for (int i = 1; i < w; i++)
      for (int j = 0; j < i; j++) {

        bool flag = true;
        for (int k = 0; k < n && flag; k++)
          if (A[k][i] < A[k][j])
            flag = false;

        if (flag)
          dp[i] = max(dp[i], 1 + dp[j]);
      }
    return w - *max_element(dp.begin(), dp.end());
  }
};
