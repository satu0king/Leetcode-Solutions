class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    unordered_map<int, int> c;
    for (auto t : time)
      c[t % 60]++;

    int ans = (c[0] * (c[0] - 1)) / 2;
    ans += (c[30] * (c[30] - 1)) / 2;

    for (int i = 1; i < 30; i++)
      ans += c[i] * c[60 - i];

    return ans;
  }
};
