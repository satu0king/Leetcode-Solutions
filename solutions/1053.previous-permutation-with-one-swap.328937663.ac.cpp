class Solution {
public:
  vector<int> prevPermOpt1(vector<int> &A) {
    int n = A.size();
    for (int i = n - 1; i >= 0; i--) {
      int idx = -1;
      for (int j = i + 1; j < n; j++)
        if (A[j] < A[i]) {
          if (~idx) {
            if (A[idx] < A[j])
              idx = j;
          } else
            idx = j;
        }
      if (~idx) {
        swap(A[i], A[idx]);
        return A;
      }
    }
    return A;
  }
};
