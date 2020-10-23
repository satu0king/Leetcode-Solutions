class Solution {
public:
  vector<int> shortestDistanceColor(vector<int> &colors,
                                    vector<vector<int>> &queries) {
    vector<vector<int>> colorIndices(4);
    for (int i = 0; i < colors.size(); i++) {
      colorIndices[colors[i]].push_back(i);
    }
    vector<int> ans;
    for (auto &q : queries) {
      int ind = q[0];
      int c = q[1];
      auto it =
          lower_bound(colorIndices[c].begin(), colorIndices[c].end(), ind);
      int a = -1;
      if (it != colorIndices[c].end())
        a = *it - ind;
      if (it != colorIndices[c].begin()) {
        if (a == -1)
          a = ind - *prev(it);
        else
          a = min(a, ind - *prev(it));
      }
      ans.push_back(a);
    }
    return ans;
  }
};

//  0 1 2 3 4 5 6 7 8
// [1,1,2,1,3,2,2,3,3]
// [0, 1, 3]
// [2, 5, 6]
// [4, 7, 8]

// Total Space - N
// In my method - 3 * N

// Search space - ([0 - n] in sorted array array)
// answer - something in search space (index in sorted array)
// if A is wrong, then either > A is also wrong or < A is also wrong (and vice
// versa)
