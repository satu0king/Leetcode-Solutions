class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target,
                                      int i = 0) {
    unordered_map<int, int> count;
    vector<int> candidates_new;
    for (int c : candidates)
      if (!count[c]++)
        candidates_new.push_back(c);

    return combinationSum2(candidates_new, target, 0, count);
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target,
                                      int i, unordered_map<int, int> &count) {
    int n = candidates.size();
    vector<vector<int>> ans;
    if (i == n)
      return ans;

    vector<int> temp1;
    for (int j = 0; j * candidates[i] <= target && j <= count[candidates[i]];
         j++) {
      if (j)
        temp1.push_back(candidates[i]);

      if (j * candidates[i] == target)
        ans.push_back(temp1);
      else {

        vector<vector<int>> temp2 = combinationSum2(
            candidates, target - j * candidates[i], i + 1, count);

        for (auto &temp3 : temp2) {
          temp3.insert(temp3.end(), temp1.begin(), temp1.end());
          ans.push_back(temp3);
        }
      }
    }

    return ans;
  }
};
