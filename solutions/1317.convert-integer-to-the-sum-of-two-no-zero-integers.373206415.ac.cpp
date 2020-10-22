class Solution {
public:
  bool check(int n) {
    while (n) {
      if (n % 10 == 0)
        return true;

      n = n / 10;
    }

    return false;
  }
  vector<int> getNoZeroIntegers(int n) {
    vector<int> ans;
    int i = n;
    while (i--) {
      int x = i;
      int y = (n - i);
      if (!check(x) and !check(y)) {
        ans.push_back(x);
        ans.push_back(y);
        return ans;
      }
    }

    return ans;
  }
};
