class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
    vector<vector<int>> temp;
    for (int i = 0; i < nums.size(); i++)
      for (int j = 0; j < nums[i].size(); j++) {
        int k = i + j;
        if (temp.size() == k)
          temp.push_back({nums[i][j]});
        else
          temp[k].push_back(nums[i][j]);
      }
    vector<int> ans;
    for (auto &row : temp)
      ans.insert(ans.end(), row.rbegin(), row.rend());
    return ans;
  }
};
