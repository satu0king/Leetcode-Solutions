class Solution {
public:
  int numTrees(int n) {
    vector<int> ans(n + 1);

    ans[0] = 1;

    for (int i = 1; i <= n; i++)
      for (int j = 0; j < i; j++)
        ans[i] += ans[j] * ans[i - j - 1];

    return ans[n];
  }
};
