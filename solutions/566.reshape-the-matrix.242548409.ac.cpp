class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
    int n1 = nums.size();
    if (!n1)
      return nums;
    int n2 = nums[0].size();
    if (n1 * n2 != r * c)
      return nums;
    vector<vector<int>> ans(r, vector<int>(c));
    for (int i = 0; i < n1; i++)
      for (int j = 0; j < n2; j++)
        ans[(i * (n2) + j) / c][(i * (n2) + j) % c] = nums[i][j];
    return ans;
  }
};
