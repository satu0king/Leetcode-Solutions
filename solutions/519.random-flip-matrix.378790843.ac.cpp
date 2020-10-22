class Solution {
  unordered_map<int, int> mp;
  int n_rows;
  int n_cols;
  int n;

public:
  Solution(int n_rows, int n_cols) : n_rows(n_rows), n_cols(n_cols) {
    n = n_rows * n_cols;
  }

  vector<int> flip() {
    int index = rand() % n;
    int actualIndex = mp.count(index) ? mp[index] : index;
    n--;
    mp[index] = mp.count(n) ? mp[n] : n;
    return {actualIndex / n_cols, actualIndex % n_cols};
  }

  void reset() {
    n = n_cols * n_rows;
    mp.clear();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
