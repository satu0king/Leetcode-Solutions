class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>> &ops) {

    for (auto op : ops)
      m = min(op[0], m), n = min(op[1], n);

    return m * n;
  }
};
