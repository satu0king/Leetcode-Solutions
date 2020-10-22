class Solution {
public:
  int sumSubseqWidths(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    vector<long> powers(n);
    powers[0] = 1;

    const int p = 1e9 + 7;

    for (int i = 1; i < n; i++)
      powers[i] = (powers[i - 1] * 2) % p;

    long ans = 0;

    for (int i = 0; i < n; i++)
      ans = (ans + (powers[i] - powers[n - i - 1]) * A[i] + p) % p;

    return ans;
  }
};
