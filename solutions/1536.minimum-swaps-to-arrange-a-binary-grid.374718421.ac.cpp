class Solution {
public:
  int minSwaps(vector<vector<int>> &grid) {
    vector<int> zeroCount;
    int n = grid.size();
    for (int i = 0; i < grid.size(); i++) {
      int c = 0;
      for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--)
        c++;
      zeroCount.push_back(c);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      bool flag = true;
      for (int j = i; j < n; j++) {
        if (zeroCount[j] >= n - i - 1) {
          flag = false;
          while (j != i) {
            ans++;
            swap(zeroCount[j], zeroCount[j - 1]);
            j--;
          }
          break;
        }
      }
      if (flag)
        return -1;
    }
    return ans;
  }
};
