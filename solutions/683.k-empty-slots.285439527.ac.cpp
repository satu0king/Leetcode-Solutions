class Solution {
public:
  int kEmptySlots(vector<int> &bulbs, int k) {
    set<int> s;
    for (int i = 0; i < bulbs.size(); i++) {
      int x = bulbs[i];
      auto it = s.upper_bound(x);
      if (it != s.end() && *it - x == k + 1)
        return i + 1;

      if (it != s.begin() && x - *prev(it) == k + 1)
        return i + 1;
      s.insert(x);
    }
    return -1;
  }
};
