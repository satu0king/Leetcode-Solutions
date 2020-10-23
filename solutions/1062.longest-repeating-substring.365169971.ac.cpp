class Solution {
  bool f(string &S, int size) {
    unordered_set<long> hashSet;
    long hash = 0;
    long h = 1;
    const long P = 1e9 + 7;
    for (int i = 0; i < size; i++) {
      hash = hash * 257 + S[i];
      hash %= P;
      if (i)
        h = (h * 257) % P;
    }
    hashSet.insert(hash);
    for (int i = size; i < S.size(); i++) {
      hash = (hash - (S[i - size] * h) % P + P) % P;
      hash = (hash * 257 + S[i]) % P;
      if (hashSet.count(hash))
        return true;
      hashSet.insert(hash);
    }
    return false;
  }

public:
  int longestRepeatingSubstring(string S) {
    int l = 1;
    int r = S.size();
    int ans = 0;
    while (l <= r) {
      int m = (l + r) / 2;
      if (f(S, m)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }
};
