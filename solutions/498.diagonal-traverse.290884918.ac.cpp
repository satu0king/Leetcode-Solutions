class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    vector<int> result;
    int i = 0;
    int j = 0;
    int n = matrix.size();
    if (!n)
      return result;
    int m = matrix[0].size();
    bool dir = 0;
    for (int i = 0; i < n; i++) {
      vector<int> temp;

      for (int ii = i, jj = 0; ii >= 0 && jj < m; ii--, jj++)
        temp.push_back(matrix[ii][jj]);

      if (dir)
        result.insert(result.end(), temp.rbegin(), temp.rend());
      else
        result.insert(result.end(), temp.begin(), temp.end());

      dir = !dir;
    }

    for (int j = 1; j < m; j++) {
      vector<int> temp;

      for (int ii = n - 1, jj = j; ii >= 0 && jj < m; ii--, jj++)
        temp.push_back(matrix[ii][jj]);

      if (dir)
        result.insert(result.end(), temp.rbegin(), temp.rend());
      else
        result.insert(result.end(), temp.begin(), temp.end());

      dir = !dir;
    }
    return result;
  }
};
