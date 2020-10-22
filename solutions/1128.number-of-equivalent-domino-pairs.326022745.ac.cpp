class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    vector<int> map(100);
    int ans = 0;
    for (auto &domino : dominoes) {
      int n1 = min(domino[0], domino[1]);
      int n2 = max(domino[0], domino[1]);
      ans += map[n1 * 10 + n2]++;
    }
    return ans;
  }
};
