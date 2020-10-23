class Solution {
public:
  vector<vector<int>> highFive(vector<vector<int>> &items) {
    unordered_map<int, vector<int>> mp;
    for (auto &item : items) {
      int id = item[0];
      int score = item[1];
      mp[id].push_back(score);
    }
    vector<vector<int>> ans;
    for (auto &[id, scores] : mp) {
      sort(scores.begin(), scores.end());
      reverse(scores.begin(), scores.end());
      int sum = accumulate(scores.begin(), scores.begin() + 5, 0);
      sum /= 5;
      ans.push_back({id, sum});
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
