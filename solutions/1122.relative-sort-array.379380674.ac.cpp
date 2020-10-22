class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    map<int, int> mp;
    for (int a : arr1)
      mp[a]++;
    vector<int> ans;
    for (int a : arr2) {
      while (mp[a]--) {
        ans.push_back(a);
      }
    }
    for (auto [v, c] : mp) {
      while (c-- > 0)
        ans.push_back(v);
    }
    return ans;
  }
};
