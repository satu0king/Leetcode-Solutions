class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    vector<int> sum(1001);
    for (auto trip : trips) {
      sum[trip[1]] += trip[0];
      sum[trip[2]] -= trip[0];
    }
    for (int i = 1; i < 1001; i++)
      sum[i] += sum[i - 1];

    for (auto n : sum)
      if (n > capacity)
        return false;
    return true;
  }
};
