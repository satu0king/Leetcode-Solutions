class Solution {
public:
  int numSubarraysWithSum(vector<int> &A, int S) {
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0]++;
    int s = 0;
    for (int a : A) {
      s += a;
      ans += mp[s - S];
      mp[s]++;
    }
    return ans;
  }
};
