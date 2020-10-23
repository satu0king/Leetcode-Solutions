class Solution {
public:
  int smallestCommonElement(vector<vector<int>> &mat) {
    int m[10001] = {};
    for (auto j = 0; j < mat[0].size(); ++j)
      for (auto i = 0; i < mat.size(); ++i)
        if (++m[mat[i][j]] == mat.size())
          return mat[i][j];
    return -1;
  }
};
