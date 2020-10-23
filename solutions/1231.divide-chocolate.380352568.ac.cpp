class Solution {

  bool f(vector<int> &sweetness, int K, int v) {
    int c = 0;
    for (int s : sweetness) {
      c += s;
      if (c >= v) {
        K--;
        c = 0;
      }
    }
    return K < 0;
  }

public:
  int maximizeSweetness(vector<int> &sweetness, int K) {
    int l = 1;
    int r = accumulate(sweetness.begin(), sweetness.end(), 0);
    int ans = 0;
    while (l <= r) {
      int m = (l + r) / 2;
      if (f(sweetness, K, m)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }
};
