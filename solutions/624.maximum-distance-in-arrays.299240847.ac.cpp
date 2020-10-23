class Solution {
public:
  int maxDistance(vector<vector<int>> &arrays) {
    vector<int> s;

    for (auto &v : arrays) {
      s.push_back(v.back());
    }

    sort(s.begin(), s.end());

    int ans = 0;

    for (auto &v : arrays) {
      if (v.back() == s.back())
        ans = max(ans, abs(v.front() - s[s.size() - 2]));
      else
        ans = max(ans, abs(v.front() - s.back()));
    }

    return ans;
  }
};
