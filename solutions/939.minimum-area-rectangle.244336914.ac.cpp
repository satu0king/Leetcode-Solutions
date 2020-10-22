class Solution {
public:
  int minAreaRect(vector<vector<int>> &points) {

    map<int, vector<int>> mp;

    for (auto p : points)
      mp[p[0]].push_back(p[1]);

    map<pair<int, int>, int> mp1;
    auto it = mp.begin();

    int ans = INT_MAX;

    while (it != mp.end()) {

      vector<int> &ycoords = it->second;
      sort(ycoords.begin(), ycoords.end());
      int x = it->first;

      int m = ycoords.size();
      for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++) {
          int y1 = ycoords[i];
          int y2 = ycoords[j];
          auto key = make_pair(y1, y2);
          if (mp1.count(key))
            ans = min(ans, (x - mp1[key]) * (y2 - y1));
          mp1[key] = x;
        }

      it++;
    }

    if (ans == INT_MAX)
      return 0;

    return ans;
  }
};
