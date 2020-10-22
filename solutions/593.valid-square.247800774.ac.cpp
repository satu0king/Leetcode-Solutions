class Solution {
public:
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {

    vector<vector<int>> v = {p1, p2, p3, p4};

    vector<int> d;

    for (int i = 0; i < 4; i++)
      for (int j = i + 1; j < 4; j++)
        d.push_back((v[i][0] - v[j][0]) * (v[i][0] - v[j][0]) +
                    (v[i][1] - v[j][1]) * (v[i][1] - v[j][1]));

    sort(d.begin(), d.end());

    return d[0] && d[0] == d[1] && d[1] == d[2] && d[2] == d[3] &&
           2 * d[3] == d[4] && d[4] == d[5];
  }
};
