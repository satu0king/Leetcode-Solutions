class Solution {

  unordered_map<int, int> p1;
  unordered_map<int, int> p2;
  unordered_map<int, int> x;
  unordered_map<int, int> y;
  set<vector<int>> lamps;

public:
  vector<int> gridIllumination(int N, vector<vector<int>> &_lamps,
                               vector<vector<int>> &queries) {

    lamps.insert(_lamps.begin(), _lamps.end());

    for (auto v : lamps) {
      int _x = v[0];
      int _y = v[1];
      x[_x]++;
      y[_y]++;
      p1[_x + _y]++;
      p2[_x - _y]++;
    }

    vector<int> ans;

    for (auto v : queries) {
      int _x = v[0];
      int _y = v[1];
      ans.push_back(x[_x] + y[_y] + p1[_x + _y] + p2[_x - _y] > 0);

      if (ans.back())
        for (int i = -1; i <= 1; i++)
          for (int j = -1; j <= 1; j++)
            del({_x + i, _y + j});
    }

    return ans;
  }

  void del(vector<int> v) {
    if (lamps.erase(v)) {
      int _x = v[0];
      int _y = v[1];
      x[_x]--;
      y[_y]--;
      p1[_x + _y]--;
      p2[_x - _y]--;
    }
  }
};
