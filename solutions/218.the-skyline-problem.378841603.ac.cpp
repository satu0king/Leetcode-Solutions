class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    int n = buildings.size();

    vector<vector<int>> arr;
    vector<vector<int>> ans;

    if (!n)
      return ans;

    for (auto b : buildings) {
      arr.push_back({b[0], b[2], 1});
      arr.push_back({b[1], b[2], -1});
    }

    sort(arr.begin(), arr.end());

    multiset<int> set;
    set.insert(0);

    for (int i = 0; i < 2 * n; i++) {
      int x = arr[i][0];
      int h = arr[i][1];
      int op = arr[i][2];

      if (op == 1)
        set.insert(h);
      else
        set.erase(set.find(h));

      if (i != 2 * n - 1 && arr[i + 1][0] == x)
        continue;

      if (ans.empty() || *set.rbegin() != ans.back()[1])
        ans.push_back({x, *set.rbegin()});
    }

    return ans;
  }
};
