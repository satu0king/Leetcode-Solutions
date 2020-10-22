class Solution {
public:
  int subarraysDivByK(vector<int> &A, int K) {
    unordered_map<int, int> mp;
    mp[0]++;
    int ans = 0;
    int sum = 0;
    for (int n : A) {
      sum = (n % K + sum + K) % K;
      ans += mp[sum];
      mp[sum]++;
    }

    return ans;
  }
};
