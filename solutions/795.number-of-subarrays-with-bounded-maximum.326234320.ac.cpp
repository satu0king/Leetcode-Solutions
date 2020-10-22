class Solution {
public:
  int numSubarrayBoundedMax(vector<int> &A, int L, int R) {
    stack<int> s;
    int n = A.size();
    vector<int> left(n);
    vector<int> right(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      while (s.size() && A[s.top()] <= A[i]) {
        int j = s.top();
        s.pop();
        right[j] = i - 1;
      }

      if (s.empty())
        left[i] = 0;
      else
        left[i] = s.top() + 1;

      s.push(i);
    }

    while (s.size()) {
      int j = s.top();
      s.pop();
      right[j] = n - 1;
    }
    for (int i = 0; i < n; i++) {
      if (L <= A[i] && A[i] <= R)
        ans += (i - left[i] + 1) * (right[i] - i + 1);
    }
    return ans;
  }
};
