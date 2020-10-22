class Solution {
public:
  bool hasGroupsSizeX(vector<int> &deck) {
    unordered_map<int, int> mp;
    for (int a : deck)
      mp[a]++;

    int ans = deck.size();

    for (auto &[k, v] : mp)
      ans = gcd(ans, v);

    return ans >= 2;
  }

  int gcd(int a, int b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }
};
