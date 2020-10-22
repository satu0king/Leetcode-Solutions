class Solution {
  vector<bool> rows;
  vector<bool> d1;
  vector<bool> d2;
  int ans;
  int n;

public:
  int totalNQueens(int n) {
    rows.resize(n);
    d1.resize(2 * n);
    d2.resize(2 * n);
    ans = 0;
    this->n = n;
    f();
    return ans;
  }

  void f(int i = 0) {
    if (i == n) {
      ans++;
      return;
    }

    for (int j = 0; j < n; j++) {
      if (rows[j] || d1[i + j] || d2[i - j + n - 1])
        continue;
      rows[j] = d1[i + j] = d2[i - j + n - 1] = true;
      f(i + 1);
      rows[j] = d1[i + j] = d2[i - j + n - 1] = false;
    }
  }
};
