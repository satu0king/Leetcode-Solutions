class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    return combinationSum(candidates, n, k);
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target,
                                     int allowed, int i = 0) {
    int n = candidates.size();
    vector<vector<int>> ans;
    if (i == n)
      return ans;

    vector<int> temp1;
    for (int j = 0; j * candidates[i] <= target && j <= 1; j++) {
      if (j)
        temp1.push_back(candidates[i]);

      if (j * candidates[i] == target) {
        if (j == allowed)
          ans.push_back(temp1);
      }

      else {

        vector<vector<int>> temp2 = combinationSum(
            candidates, target - j * candidates[i], allowed - j, i + 1);

        for (auto &temp3 : temp2) {
          temp3.insert(temp3.end(), temp1.begin(), temp1.end());
          ans.push_back(temp3);
        }
      }
    }

    return ans;
  }
};
