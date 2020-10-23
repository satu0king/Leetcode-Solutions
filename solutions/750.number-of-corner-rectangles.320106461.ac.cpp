class Solution {
public:
  int countCornerRectangles(vector<vector<int>> &grid) {
    map<pair<int, int>, int> s;
    int ans = 0;

    for (auto &row : grid) {
      for (int i = 0; i < row.size(); i++)
        for (int j = i + 1; j < row.size(); j++) {
          if (row[i] && row[j]) {
            auto p = make_pair(i, j);
            ans += s[p]++;
          }
        }
    }

    return ans;
  }
};
