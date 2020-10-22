class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
    return max(f(A, L, M), f(A, M, L));
  }

  int f(vector<int> &A, int L, int M) {
    int ans = accumulate(A.begin(), A.begin() + L + M, 0);
    int leftMax = accumulate(A.begin(), A.begin() + L, 0);
    int leftSum = leftMax;
    int rightSum = ans - leftSum;

    for (int i = L + M; i < A.size(); i++) {
      leftSum -= A[i - L - M];
      leftSum += A[i - M];
      leftMax = max(leftMax, leftSum);
      rightSum -= A[i - M];
      rightSum += A[i];
      ans = max(ans, leftMax + rightSum);
    }
    return ans;
  }
};
