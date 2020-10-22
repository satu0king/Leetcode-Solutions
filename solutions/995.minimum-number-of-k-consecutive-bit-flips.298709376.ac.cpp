class Solution {
public:
  int minKBitFlips(vector<int> &A, int K) {
    int n = A.size();
    vector<int> flips(n + 1);
    int ans = 0;
    for (int i = 0; i <= n - K; i++) {
      flips[i] += i ? flips[i - 1] : 0;
      flips[i] %= 2;
      if (flips[i] ^ A[i] == 0) {
        flips[i]++;
        ans++;
        flips[i + K]++;
      }
    }

    for (int i = n - K + 1; i < n; i++) {
      flips[i] += i ? flips[i - 1] : 0;
      flips[i] %= 2;
      if (flips[i] ^ A[i] == 0)
        return -1;
    }

    return ans;
  }
};
