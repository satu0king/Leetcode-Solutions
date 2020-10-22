class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &arr) {
    int n = arr.size();

    vector<int> suffixPrefix(n, INT_MAX);

    for (int i = 1; i < n; i++) {

      suffixPrefix.assign(n, INT_MAX);
      for (int j = n - 2; j >= 0; j--)
        suffixPrefix[j] = min(suffixPrefix[j + 1], arr[i - 1][j + 1]);

      int mn = INT_MAX;

      for (int j = 0; j < n; j++) {
        arr[i][j] += min(mn, suffixPrefix[j]);
        mn = min(mn, arr[i - 1][j]);
      }
    }

    return *min_element(arr[n - 1].begin(), arr[n - 1].end());
  }
};
