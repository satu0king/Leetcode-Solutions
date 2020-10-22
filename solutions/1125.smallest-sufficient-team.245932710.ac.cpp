class Solution {
public:
  vector<int> smallestSufficientTeam(vector<string> &req_skills,
                                     vector<vector<string>> &_people) {
    unordered_map<string, int> revMap;
    int i = 0;
    for (auto skill : req_skills) {
      revMap[skill] = 1 << i;
      i++;
    }

    vector<int> people;
    for (auto &person : _people) {
      int p = 0;
      for (auto &s : person)
        p |= revMap[s];
      people.push_back(p);
    }
    int n = req_skills.size();

    unordered_map<int, vector<int>> dp;
    dp.reserve(1 << n);
    dp[0] = {};
    int m = people.size();
    for (int i = 0; i < m; i++) {
      for (auto it = dp.begin(); it != dp.end(); it++) {
        auto &p = *it;
        if (!dp.count(p.first | people[i]) ||
            dp[p.first | people[i]].size() > p.second.size() + 1) {
          dp[p.first | people[i]] = p.second;
          dp[p.first | people[i]].push_back(i);
        }
      }
    }

    return dp[(1 << n) - 1];
  }
};
