class Solution {
public:
  int oddCells(int n, int m, vector<vector<int>> &indices) {
    unordered_map<int, int> row;
    unordered_map<int, int> col;
    for (auto &v : indices) {
      row[v[0]]++;
      col[v[1]]++;
    }

    int o1 = 0;

    int o2 = 0;

    for (auto &p : row)
      if (p.second % 2)
        o1++;
    for (auto &p : col)
      if (p.second % 2)
        o2++;
    int e1 = n - o1;
    int e2 = m - o2;

    return e1 * o2 + e2 * o1;
  }
};
