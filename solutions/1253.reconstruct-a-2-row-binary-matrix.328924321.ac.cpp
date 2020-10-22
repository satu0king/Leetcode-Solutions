class Solution {
public:
  vector<vector<int>> reconstructMatrix(int upper, int lower,
                                        vector<int> &colsum) {
    int m = colsum.size();
    vector<vector<int>> ans(2, vector<int>(m));
    for (int i = 0; i < m; i++) {
      if (colsum[i] == 2) {
        ans[0][i] = 1;
        ans[1][i] = 1;
      } else if (colsum[i] == 1) {
        if (upper > lower)
          ans[0][i] = 1;
        else
          ans[1][i] = 1;
      }
      upper -= ans[0][i];
      lower -= ans[1][i];
    }

    if (upper || lower)
      return {};

    return ans;
  }
};
