class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int> &b) {
    short m[10001] = {};
    short max_cnt = 0, max_n = 0, pos = 0;
    for (auto n : b) {
      max_cnt = max(max_cnt, ++m[n]);
      max_n = max_cnt == m[n] ? n : max_n;
    }
    for (auto i = 0; i <= 10000; ++i) {
      auto n = i == 0 ? max_n : i;
      while (m[n]-- > 0) {
        b[pos] = n;
        pos = pos + 2 < b.size() ? pos + 2 : 1;
      }
    }
    return b;
  }
};
