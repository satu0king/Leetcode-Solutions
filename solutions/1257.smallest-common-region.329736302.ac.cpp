class Solution {
public:
  string findSmallestRegion(vector<vector<string>> &regions, string region1,
                            string region2) {
    unordered_map<string, string> mp;
    for (auto &v : regions) {
      for (int i = 1; i < v.size(); i++)
        mp[v[i]] = v[0];
    }

    vector<string> path1 = {region1};
    while (mp.count(region1)) {
      region1 = mp[region1];
      path1.push_back(region1);
    }

    vector<string> path2 = {region2};
    while (mp.count(region2)) {
      region2 = mp[region2];
      path2.push_back(region2);
    }
    reverse(path1.begin(), path1.end());
    reverse(path2.begin(), path2.end());
    int n = min(path1.size(), path2.size());

    for (int i = 0; i < n; i++) {
      if (i == n - 1 || path1[i + 1] != path2[i + 1])
        return path1[i];
    }

    return "";
  }
};
