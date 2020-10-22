class Solution {
  unordered_map<int, int> mp1;
  unordered_map<int, int> mp2;

public:
  int subarraysWithKDistinct(vector<int> &A, int K) {
    int ans = 0;
    int l1 = 0;
    int l2 = 0;
    int r = 0;
    int n = A.size();

    while (r < n) {

      mp1[A[r]]++;
      mp2[A[r]]++;

      while (mp1.size() > K) {
        mp1[A[l1]]--;
        if (mp1[A[l1]] == 0)
          mp1.erase(A[l1]);
        l1++;
      }

      while (mp2.size() >= K) {
        mp2[A[l2]]--;
        if (mp2[A[l2]] == 0)
          mp2.erase(A[l2]);
        l2++;
      }

      ans += l2 - l1;

      r++;
    }

    return ans;
  }
};
