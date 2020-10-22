class Solution {
public:
  int minSetSize(vector<int> &arr) {
    unordered_map<int, int> mp;
    int maxFreq = 0;
    for (int a : arr)
      maxFreq = max(maxFreq, ++mp[a]);
    vector<int> freqCount(maxFreq + 1);
    for (auto p : mp)
      freqCount[p.second]++;
    int ans = 0;
    int c = 0;
    int freq = maxFreq;
    while (1) {
      if (freqCount[freq]-- == 0) {
        freq--;
        continue;
      }
      ans++;
      c += freq;
      if (2 * c >= arr.size())
        return ans;
    }
    return -1;
  }
};
