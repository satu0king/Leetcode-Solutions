class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    vector<pair<int, int>> mp;
    for (int i = 0; i < mat.size(); i++) {
      int s = accumulate(mat[i].begin(), mat[i].end(), 0);
      mp.emplace_back(s, i);
    }
    sort(mp.begin(), mp.end());
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
      ans[i] = mp[i].second;
    return ans;
  }
};
