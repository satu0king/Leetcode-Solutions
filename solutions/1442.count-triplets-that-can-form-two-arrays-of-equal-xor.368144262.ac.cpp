class Solution {
public:
  int countTriplets(vector<int> &arr) {
    unordered_map<int, int> count;
    unordered_map<int, int> indexSum;
    int prefix = 0;
    int ans = 0;
    count[0] = 1;
    indexSum[0] = -1;
    for (int i = 0; i < arr.size(); i++) {
      prefix ^= arr[i];
      ans += count[prefix]++ * (i - 1) - indexSum[prefix];
      indexSum[prefix] += i;
    }
    return ans;
  }
};
