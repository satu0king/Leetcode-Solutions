class Solution {
public:
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    for (int i = 1; i < arr.size(); i++)
      arr[i] ^= arr[i - 1];
    vector<int> ans;
    for (auto &q : queries) {
      int t = arr[q[1]];
      if (q[0])
        t ^= arr[q[0] - 1];
      ans.push_back(t);
    }
    return ans;
  }
};
