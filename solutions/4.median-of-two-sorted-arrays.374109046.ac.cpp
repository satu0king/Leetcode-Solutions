class Solution {
public:
  double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    return (kth(A, B, (n + m + 1) / 2) + kth(A, B, (n + m + 2) / 2)) / 2.0;
  }

  int kth(vector<int> &A, vector<int> &B, int k) {
    int n = A.size();
    int m = B.size();

    int l = 0;
    int r = n;

    while (l <= r) {
      int cA = (l + r) / 2;
      int cB = k - cA;
      if (cB > m) {
        l = cA + 1;
      } else if (cB < 0) {
        r = cA - 1;
      } else if (cA && cB < m && A[cA - 1] > B[cB]) {
        r = cA - 1;
      } else if (cB && cA < n && B[cB - 1] > A[cA]) {
        l = cA + 1;
      } else {
        int candidate = INT_MIN;
        if (cA >= 1)
          candidate = max(candidate, A[cA - 1]);
        if (cB >= 1)
          candidate = max(candidate, B[cB - 1]);
        return candidate;
      }
    }
    return -1;
  }
};
