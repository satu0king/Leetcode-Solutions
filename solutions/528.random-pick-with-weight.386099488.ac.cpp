class Solution {
public:
  vector<int> p;
  int total = 0;
  Solution(vector<int> &w) {
    int prev = 0;

    for (auto &e : w) {
      p.push_back(prev + e);
      prev += e;
    }
    total = prev;
  }

  int pickIndex() {
    int ind = rand() % total;
    ind++;
    auto itr = lower_bound(p.begin(), p.end(), ind);
    return itr - p.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
