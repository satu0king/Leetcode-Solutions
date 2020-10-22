class Solution {
public:
  int numTimesAllBlue(vector<int> &A) {
    int right = 0, res = 0, n = A.size();
    for (int i = 0; i < n; ++i)
      res += (right = max(right, A[i])) == i + 1;
    return res;
  }
};
