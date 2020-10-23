class Solution {
public:
  string stringShift(string s, vector<vector<int>> &shift) {
    int move = 0;
    int n = s.size();

    for (auto &v : shift)
      if (!v[0])
        move += v[1];
      else
        move += n - v[1];

    move %= n;

    s += s;
    return s.substr(move, n);
  }
};
