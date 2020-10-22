class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    int i = 0;
    int j = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<vector<int>> ans;
    set<vector<int>> set;
    if (!n1 || !n2)
      return ans;

    for (int i = 0; i < n2 && i < k; i++)
      set.insert({nums2[i] + nums1[0], 0, i});

    while (k-- && set.size()) {
      auto v = *(set.begin());
      set.erase(v);
      ans.push_back({nums1[v[1]], nums2[v[2]]});
      v[1]++;
      if (v[1] < n1)
        set.insert({nums2[v[2]] + nums1[v[1]], v[1], v[2]});
    }

    return ans;
  }
};
