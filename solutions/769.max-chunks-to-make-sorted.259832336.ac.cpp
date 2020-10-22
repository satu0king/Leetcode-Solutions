class Solution {
public:
  int maxChunksToSorted(vector<int> &arr) {
    int ans = 0;
    int r = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      r = max(r, arr[i]);
      if (r == i)
        ans++;
    }

    return ans;
  }
};
