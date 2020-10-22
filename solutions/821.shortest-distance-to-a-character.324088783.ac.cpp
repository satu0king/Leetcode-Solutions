class Solution {
public:
  vector<int> shortestToChar(string S, char C) {
    int n = S.size();
    vector<int> ans(n, n);
    int d = n;
    for (int i = 0; i < n; i++) {
      if (S[i] == C)
        d = 0;
      ans[i] = min(ans[i], d);
      d++;
    }
    d = n;
    for (int i = n - 1; i >= 0; i--) {
      if (S[i] == C)
        d = 0;
      ans[i] = min(ans[i], d);
      d++;
    }

    return ans;
  }
};
