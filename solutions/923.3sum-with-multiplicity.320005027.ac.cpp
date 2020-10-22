class Solution {
public:
  int threeSumMulti(vector<int> &A, int target) {
    unordered_map<int, int> mp;
    sort(A.begin(), A.end());
    for (int a : A)
      mp[a]++;
    A.erase(unique(A.begin(), A.end()), A.end());

    long long ans = 0;
    int p = 1e9 + 7;

    int n = A.size();

    for (int i = 0; i < n; i++) {
      int j = i;
      int k = n - 1;
      while (j <= k) {
        if (A[i] + A[j] + A[k] > target)
          k--;
        else if (A[i] + A[j] + A[k] < target)
          j++;
        else {
          if (i == j && j == k) {
            long long t = mp[A[i]];
            ans += (t * (t - 1) * (t - 2)) / 6;
          } else if (i == j) {
            long long t1 = mp[A[i]];
            long long t2 = mp[A[k]];
            ans += (t1 * (t1 - 1) * t2) / 2;

          } else if (j == k) {
            int t1 = mp[A[j]];
            int t2 = mp[A[i]];
            ans += t1 * (t1 - 1) * t2 / 2;
          } else
            ans += (long long)mp[A[i]] * mp[A[j]] * mp[A[k]];

          ans %= p;

          // cout << i <<" " << j <<" " << k << " " << ans << endl;
          j++;
          k--;
        }
      }
    }

    return ans;
  }
};
