class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> DP(rowIndex + 1);
    DP[0] = 1;
    while (rowIndex--) {
      for (int i = DP.size() - 1; i > 0; i--)
        DP[i] += DP[i - 1];
    }
    return DP;
  }
};
