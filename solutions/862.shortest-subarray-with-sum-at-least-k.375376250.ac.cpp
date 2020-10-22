class Solution {
public:
  int shortestSubarray(vector<int> &A, int K) {
    deque<int> dq;
    int ans = -1;
    for (int i = 1; i < A.size(); i++)
      A[i] += A[i - 1];
    A.insert(A.begin(), 0);
    for (int i = 0; i < A.size(); i++) {
      while (dq.size() && A[dq.back()] >= A[i])
        dq.pop_back();
      while (dq.size() && A[i] - A[dq.front()] >= K) {
        if (ans == -1 || i - dq.front() < ans)
          ans = i - dq.front();
        dq.pop_front();
      }
      dq.push_back(i);
    }
    return ans;
  }
};
