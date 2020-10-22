class Solution {
public:
  int minHeightShelves(vector<vector<int>> &books, int shelf_width) {
    int n = books.size();
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      int h = books[i - 1][1];
      int remainingWidth = shelf_width - books[i - 1][0];
      dp[i] = dp[i - 1] + h;
      int j = i - 1;
      while (j) {
        h = max(books[j - 1][1], h);
        int w = books[j - 1][0];
        remainingWidth -= w;
        if (remainingWidth < 0)
          break;
        dp[i] = min(dp[i], dp[j - 1] + h);
        j--;
      }
    }
    return dp.back();
  }
};
