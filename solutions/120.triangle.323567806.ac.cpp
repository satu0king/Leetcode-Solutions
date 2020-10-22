class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    if (n <= 0)
      return 0;

    for (int i = 1; i < n; i++) {
      for (int j = i; j >= 0; j--)
        triangle[i][j] += min(j < i ? triangle[i - 1][j] : INT_MAX,
                              j > 0 ? triangle[i - 1][j - 1] : INT_MAX);
    }

    return *min_element(triangle.back().begin(), triangle.back().end());
  }
};
