class Solution {
public:
  int longestOnes(vector<int> &A, int K) {
    vector<int> count(2);
    int l = 0;
    int r = 0;
    int n = A.size();
    int ans = 0;

    while (l <= r && r < n) {

      count[A[r++]]++;

      while (count[0] > K)
        count[A[l++]]--;

      ans = max(ans, r - l);
    }

    return ans;
  }
};
