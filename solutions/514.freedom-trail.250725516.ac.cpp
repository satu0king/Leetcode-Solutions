class Solution {

  unordered_map<char, vector<int>> map;
  vector<vector<int>> dp;
  int n1;
  int n2;

public:
  int findRotateSteps(string ring, string key) {

    n1 = ring.size();
    n2 = key.size();

    for (int i = 0; i < n1; i++)
      map[ring[i]].push_back(i);

    dp = vector<vector<int>>(n2, vector<int>(n1, -1));

    return findRotateSteps(key);
  }

  int findRotateSteps(string &key, int i = 0, int j = 0) {
    if (i == n2)
      return 0;

    if (~dp[i][j])
      return dp[i][j];

    vector<int> &indices = map[key[i]];

    int right = indices[0];
    int left = indices[0];

    for (int k = 1; k < indices.size(); k++) {
      if (difR(j, indices[k]) < difR(j, right))
        right = indices[k];
      if (difL(j, indices[k]) < difL(j, left))
        left = indices[k];
    }

    dp[i][j] = min(findRotateSteps(key, i + 1, left) + dif(j, left),
                   findRotateSteps(key, i + 1, right) + dif(j, right)) +
               1;

    return dp[i][j];
  }

  int difR(int i, int j) { return (j - i + n1) % n1; }
  int difL(int i, int j) { return (i - j + n1) % n1; }
  int dif(int i, int j) { return min(difR(i, j), difL(i, j)); }
};
