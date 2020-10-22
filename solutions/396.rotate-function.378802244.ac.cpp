class Solution {
public:
  int maxRotateFunction(vector<int> &A) {
    long int sum = 0;
    long int score = 0;
    for (int i = 0; i < A.size(); i++) {
      sum += A[i];
      score += A[i] * i;
    }
    long int ans = score;
    for (int i = 0; i < A.size(); i++) {
      score -= sum - A[i];
      score += A[i] * (A.size() - 1);
      ans = max(ans, score);
    }
    return ans;
  }
};
