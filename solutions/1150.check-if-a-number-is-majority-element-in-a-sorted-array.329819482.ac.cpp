class Solution {
public:
  bool isMajorityElement(vector<int> &n, int t) {
    return upper_bound(begin(n), end(n), t) - lower_bound(begin(n), end(n), t) >
           n.size() / 2;
  }
};
