class Solution {
public:
  int numSquarefulPerms(vector<int> &A) {
    unordered_map<int, int> mp;
    unordered_map<int, int> c;
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
      ans += f(A, 1 << i, i, mp);
      c[A[i]]++;
    }

    vector<int> factorial(A.size() + 1, 1);
    for (int i = 2; i <= A.size(); i++)
      factorial[i] = factorial[i - 1] * i;

    for (auto [k, v] : c)
      ans /= factorial[v];

    return ans;
  }

  int f(vector<int> &A, int mask, int prevI, unordered_map<int, int> &mp) {
    int n = A.size();

    if (mask == (1 << n) - 1)
      return 1;

    int key = mask + (prevI << n);
    if (mp.count(key))
      return mp[key];

    int ans = 0;

    int prev = A[prevI];

    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i)) && isSquare(prev + A[i])) {
        mask ^= 1 << i;
        ans += f(A, mask, i, mp);
        mask ^= 1 << i;
      }
    }

    return mp[key] = ans;
  }

  bool isSquare(int n) {
    int s = sqrt(n) + 0.5;
    return s * s == n;
  }
};
