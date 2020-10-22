class Solution {

public:
  int kthSmallest(vector<vector<int>> &mat, int k) {

    vector<int> arr = {0};
    int m = min((int)mat[0].size(), k);
    for (auto &row : mat) {
      vector<int> b;
      for (int a : arr)
        for (int j = 0; j < m; j++)
          b.push_back(a + row[j]);
      sort(b.begin(), b.end());
      b.erase(b.begin() + min(k, (int)b.size()), b.end());
      arr = move(b);
    }

    return arr[k - 1];
  }
};
