class Solution {
public:
  vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> ans;
    for (int i = 1; i <= 9; i++)
      f(ans, N - 1, K, i);

    if (N == 1)
      ans.push_back(0);

    return ans;
  }

  void f(vector<int> &ans, int n, int k, int num) {
    if (n == 0) {
      ans.push_back(num);
      return;
    }

    int current = num % 10;

    if (current + k <= 9)
      f(ans, n - 1, k, num * 10 + current + k);

    if (current - k >= 0 && k != 0)
      f(ans, n - 1, k, num * 10 + current - k);
  }
};
