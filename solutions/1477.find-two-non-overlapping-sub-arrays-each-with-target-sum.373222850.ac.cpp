class Solution {
public:
  int minSumOfLengths(vector<int> &arr, int target) {
    int n = arr.size();
    vector<int> bestTill(n, -1);
    int l = 0;
    int s = 0;
    for (int r = 0; r < n; r++) {
      s += arr[r];
      while (s > target)
        s -= arr[l++];
      if (r)
        bestTill[r] = bestTill[r - 1];
      if (s == target) {
        if (bestTill[r] == -1 || r - l + 1 < bestTill[r]) {
          bestTill[r] = r - l + 1;
        }
      }
    }
    int ans = -1;
    l = 0;
    s = 0;
    for (int r = 0; r < n; r++) {
      s += arr[r];
      while (s > target)
        s -= arr[l++];
      if (s == target && l && ~bestTill[l - 1]) {
        if (ans == -1 || bestTill[l - 1] + r - l + 1 < ans) {
          ans = bestTill[l - 1] + r - l + 1;
        }
      }
    }
    return ans;
  }
};
