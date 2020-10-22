class Solution {
public:
  bool f(vector<int> &piles, int K, int H) {
    for (auto p : piles)
      H -= ceil(p / (K + 0.0));
    return H >= 0;
  }

  int minEatingSpeed(vector<int> &piles, int H) {
    int l = 0;
    int r = *max_element(piles.begin(), piles.end());

    int ans = r;
    while (l <= r) {
      int m = (l + r) / 2;
      if (f(piles, m, H)) {
        ans = m;
        r = m - 1;
      } else
        l = m + 1;
    }
    return ans;
  }
};
