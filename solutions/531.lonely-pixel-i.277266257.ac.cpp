class Solution {
public:
  int findLonelyPixel(vector<vector<char>> &picture) {
    int ans = 0;
    int n = picture.size();
    int m = picture[0].size();
    vector<int> v(n);
    vector<int> h(m);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (picture[i][j] == 'B')
          v[i]++, h[j]++;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (picture[i][j] == 'B' && v[i] == 1 && h[j] == 1)
          ans++;

    return ans;
  }
};
