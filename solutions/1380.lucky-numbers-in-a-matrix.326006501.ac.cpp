class Solution {
public:
  vector<int> luckyNumbers(vector<vector<int>> &matrix) {
    int n = matrix.size();
    if (!n)
      return {};
    int m = matrix[0].size();

    vector<int> rowMin(n);
    vector<int> colMax(m, 0);
    for (int i = 0; i < n; i++) {
      rowMin[i] = *min_element(matrix[i].begin(), matrix[i].end());
      for (int j = 0; j < m; j++)
        colMax[j] = max(colMax[j], matrix[i][j]);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (rowMin[i] == matrix[i][j] && colMax[j] == matrix[i][j])
          ans.push_back(matrix[i][j]);
    }

    return ans;
  }
};
