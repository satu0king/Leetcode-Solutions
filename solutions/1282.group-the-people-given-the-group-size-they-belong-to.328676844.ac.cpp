class Solution {
public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < groupSizes.size(); i++)
      mp[groupSizes[i]].push_back(i);

    for (auto &[g, people] : mp) {
      for (int i = 0; i < people.size(); i += g) {
        vector<int> temp(people.begin() + i, people.begin() + i + g);
        ans.push_back(temp);
      }
    }
    return ans;
  }
};
