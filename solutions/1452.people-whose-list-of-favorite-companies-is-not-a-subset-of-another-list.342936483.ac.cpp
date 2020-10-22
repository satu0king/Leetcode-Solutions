class Solution {
public:
  vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies) {
    int n = favoriteCompanies.size();
    unordered_map<string, int> mp;
    int c = 0;
    for (auto &v : favoriteCompanies)
      for (auto &s : v)
        if (!mp.count(s))
          mp[s] = c++;

    vector<bitset<50000>> arr(n);
    for (int i = 0; i < n; i++)
      for (auto &s : favoriteCompanies[i])
        arr[i][mp[s]] = 1;

    vector<int> ans;

    for (int i = 0; i < n; i++) {
      bool flag = true;
      for (int j = 0; j < n && flag; j++)
        if (i != j && (arr[i] & arr[j]) == arr[i])
          flag = false;

      if (flag)
        ans.push_back(i);
    }

    return ans;
  }
};
