class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &A) {

    int n = A.size();
    vector<unordered_map<long long, int>> mp(n);

    unordered_set<int> s(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        long long d = (long long)A[i] - A[j];

        if (mp[j].count(d))
          ans += mp[j][d];

        if (s.count(A[i] + d))
          mp[i][d] += (mp[j].count(d) ? mp[j][d] : 0) + 1;
      }
    }

    return ans;
  }
};
