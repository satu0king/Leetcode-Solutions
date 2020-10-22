class Solution {
public:
  int numOfSubarrays(vector<int> &arr) {
    const int p = 1e9 + 7;
    long ans = 0;
    int count[2] = {1, 0};
    int s = 0;
    for (int a : arr) {
      s += a;
      s %= 2;
      ans += count[(s + 1) % 2];
      count[s]++;
    }
    return ans % p;
  }
};
