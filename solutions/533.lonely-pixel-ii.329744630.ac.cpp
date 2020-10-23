class Solution {
public:
  int findBlackPixel(vector<vector<char>> &picture, int N) {
    int n = picture.size();
    if (!n)
      return 0;
    int m = picture[0].size();
    vector<int> colCount(m);
    vector<int> rowCount(n);
    vector<string> rowHash(n);
    unordered_map<string, int> hashCount;
    const int p = 1e9 + 7;

    for (int i = 0; i < n; i++) {
      rowHash[i] = string(picture[i].begin(), picture[i].end());
      rowCount[i] = count(picture[i].begin(), picture[i].end(), 'B');
      hashCount[rowHash[i]]++;
    }

    for (int j = 0; j < m; j++)
      for (int i = 0; i < n; i++)
        if (picture[i][j] == 'B')
          colCount[j]++;

    int ans = 0;

    for (int j = 0; j < m; j++) {
      if (colCount[j] != N)
        continue;

      for (int i = 0; i < n; i++) {
        if (picture[i][j] == 'B') {
          if (rowCount[i] != N)
            break;
          if (hashCount[rowHash[i]] != N)
            break;
          ans += N;
          break;
        }
      }
    }

    return ans;
  }
};
