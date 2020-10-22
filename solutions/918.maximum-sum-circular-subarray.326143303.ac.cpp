class Solution {
public:
  int maxSubarraySumCircular(vector<int> &A) {
    int n = A.size();
    A.insert(A.end(), A.begin(), A.end());
    deque<int> q;
    int s = 0;
    int ans = A[0];
    for (int i = 0; i < 2 * n; i++) {
      s += A[i];
      ans = max(ans, A[i]);
      A[i] = s;

      while (q.size() && A[q.back()] >= s)
        q.pop_back();
      while (q.size() && q.front() + n < i)
        q.pop_front();

      if (q.size())
        ans = max(ans, s - A[q.front()]);
      q.push_back(i);
    }

    return ans;
  }
};
