struct nd {
  int a, b, c;
};
bool cmp(const nd &a, const nd &b) {
  if (a.a != b.a) {
    return a.a < b.a;
  } else if (a.b != b.b) {
    return a.b < b.b;
  } else {
    return a.c < b.c;
  }
}
class Solution {
public:
  vector<int> assignBikes(vector<vector<int>> &workers,
                          vector<vector<int>> &bikes) {
    vector<nd> a;
    int n = workers.size();
    int m = bikes.size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int x1 = workers[i][0];
        int y1 = workers[i][1];
        int x2 = bikes[j][0];
        int y2 = bikes[j][1];
        a.push_back({abs(x1 - x2) + abs(y1 - y2), i, j});
      }
    sort(a.begin(), a.end(), cmp);

    vector<bool> bikesDone(m);
    vector<int> ans(n, -1);

    for (auto v : a) {
      int w = v.b;
      int b = v.c;
      if (~ans[w] || bikesDone[b])
        continue;
      bikesDone[b] = 1;
      ans[w] = b;
    }
    return ans;
  }
};
