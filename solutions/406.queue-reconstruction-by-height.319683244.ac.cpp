
class Solution {

public:
  static bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] != b[0])
      return a[0] > b[0];
    return a[1] < b[1];
  }

  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(), cmp);

    vector<vector<int>> ans;

    for (auto v : people)
      ans.insert(ans.begin() + v[1], v);

    return ans;
  }
};
