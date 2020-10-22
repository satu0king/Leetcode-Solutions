class Solution {
public:
  int minIncrementForUnique(vector<int> &A) {
    if (A.empty())
      return 0;
    sort(A.begin(), A.end());
    int ans = 0;
    int mx = A[0] - 1;
    for (int a : A) {
      ans += max(0, mx + 1 - a);
      mx = max(mx + 1, a);
    }
    return ans;
  }
};
