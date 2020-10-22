class Solution {
public:
  int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {

    unordered_map<int, char> mp;

    for (auto &v : reservedSeats)
      if (v[1] > 1 && v[1] < 10)
        mp[v[0] - 1] |= 1 << (v[1] - 2);

    int ans = n * 2;

    for (auto &[_, c] : mp) {

      bool c1 = !(c & 0b11110000);
      bool c2 = !(c & 0b00001111);
      bool c3 = !(c & 0b00111100);

      if (c1 || c2 || c3)
        ans--;
      else
        ans -= 2;
    }

    return ans;
  }
};
