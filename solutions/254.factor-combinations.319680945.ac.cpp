class Solution {
public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> ans;
    vector<int> factors;
    f(ans, factors, n);
    return ans;
  }

  void f(vector<vector<int>> &ans, vector<int> &factors, int n) {
    int candidate = factors.size() ? factors.back() : 2;

    for (int i = candidate; i * i <= n; i++) {
      if (n % i == 0) {
        factors.push_back(i);
        factors.push_back(n / i);
        ans.push_back(factors);
        factors.pop_back();
        f(ans, factors, n / i);
        factors.pop_back();
      }
    }
  }
};
