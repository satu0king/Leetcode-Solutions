class Solution {
public:
  int findJudge(int N, vector<vector<int>> &trust) {
    unordered_map<int, int> m1; // trusted
    unordered_map<int, int> m2; // trusts

    for (auto p : trust) {
      m2[p[0]]++;
      m1[p[1]]++;
    }

    if (N == 1)
      return 1;

    int candidate = -1;

    for (auto p : m1) {
      if (p.second == N - 1 && !m2[p.first])
        candidate = p.first;
    }
    return candidate;
  }
};
