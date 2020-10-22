class Solution {
  static bool compartor(vector<int> &v1, vector<int> &v2) {
    if (v1[0] != v2[0])
      return v1[0] > v2[0];
    return v1[1] < v2[1];
  }

public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(), compartor);

    set<int> stack;

    for (auto v : envelopes) {
      if (!stack.empty() && v[1] >= *stack.begin()) {
        auto it = stack.upper_bound(v[1]);
        stack.erase(prev(it));
      }
      stack.insert(v[1]);
    }

    return stack.size();
  }
};
