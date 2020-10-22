class Solution {
public:
  int sumSubarrayMins(vector<int> &A) {
    const long p = 1e9 + 7;
    long ans = 0;
    int n = A.size();
    vector<int> left(n, -1);
    vector<int> right(n, -1);

    stack<int> s;
    for (int i = 0; i < n; i++) {
      while (s.size() && A[s.top()] >= A[i]) {
        int j = s.top();
        right[j] = i - 1;
        s.pop();
      }

      if (s.empty())
        left[i] = 0;
      else
        left[i] = s.top() + 1;

      s.push(i);
    }

    while (s.size()) {
      int j = s.top();
      right[j] = n - 1;
      s.pop();
    }

    for (int i = 0; i < n; i++) {
      ans += A[i] * (i - left[i] + 1) * (right[i] - i + 1);
      ans %= p;
    }

    return ans;
  }
};
