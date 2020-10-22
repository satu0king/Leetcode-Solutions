class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty())
      return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> heights(m);

    int ans = 0;

    for (int i = 0; i < n; i++) {

      for (int j = 0; j < m; j++)
        if (matrix[i][j] == '0')
          heights[j] = 0;
        else
          heights[j]++;

      ans = max(ans, maximalHistogram(heights));
    }

    return ans;
  }

  int maximalHistogram(vector<int> &heights) {
    int ans = 0;

    vector<int> stack;

    heights.push_back(0);

    int n = heights.size();
    for (int i = 0; i < n; i++) {
      while (stack.size() && heights[stack.back()] > heights[i]) {
        int h = heights[stack.back()];
        stack.pop_back();
        int prevInd = stack.size() ? stack.back() : -1;
        ans = max(ans, h * (i - prevInd - 1));
      }
      stack.push_back(i);
    }

    heights.pop_back();

    return ans;
  }
};
