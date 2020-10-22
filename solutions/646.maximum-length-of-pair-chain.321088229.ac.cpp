class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) {
    vector<int> stack;
    sort(pairs.begin(), pairs.end());

    for (auto &p : pairs) {
      int s = p[0];
      int e = p[1];

      if (stack.empty() || stack.back() < s)
        stack.push_back(e);
      else {
        auto it = upper_bound(stack.begin(), stack.end(), e);
        if (it == stack.begin() || *prev(it) < s)
          *it = min(*it, e);
      }
    }

    return stack.size();
  }
};
