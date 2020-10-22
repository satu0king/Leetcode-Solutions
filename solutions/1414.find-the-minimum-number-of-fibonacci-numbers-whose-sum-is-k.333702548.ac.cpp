class Solution {
public:
  int findMinFibonacciNumbers(int k) {
    vector<int> fib = {1, 1};
    while (fib.back() < k)
      fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);

    int ans = 0;
    while (k) {
      if (fib.back() <= k) {
        k -= fib.back();
        ans++;
      }

      fib.pop_back();
    }
    return ans;
  }
};
