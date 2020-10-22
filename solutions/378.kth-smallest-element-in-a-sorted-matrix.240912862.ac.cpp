class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    if (n == 0)
      return 0;

    long long int l = matrix[0][0];
    long long int r = matrix[n - 1][n - 1];
    long long int ans;

    while (l <= r) {
      int mid = (l + r) / 2;
      int count = lessThanEqual(matrix, mid);
      if (count < k)
        l = mid + 1;
      else {
        r = mid - 1;
        ans = mid;
      }
    }
    return ans;
  }

  int lessThanEqual(vector<vector<int>> &matrix, int val) {
    int n = matrix.size();
    if (n == 0)
      return 0;

    int i = 0;
    int j = n - 1;
    int count = 0;
    while (i < n && j >= 0) {
      if (matrix[i][j] > val)
        j--;
      else {
        count += j + 1;
        i++;
      }
    }

    return count;
  }
};
