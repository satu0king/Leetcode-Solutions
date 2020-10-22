class Solution {
public:
  bool containsPattern(vector<int> &arr, int m, int k) {
    int n = arr.size();
    if (k * m > n)
      return false;
    int l = k * m;
    for (int i = 0; i + l - 1 < n; i++) {
      bool flag = true;
      for (int j = 1; j < k && flag; j++) {
        for (int h = 0; h < m && flag; h++) {
          if (arr[i + h] != arr[i + j * m + h])
            flag = false;
        }
      }
      if (flag)
        return true;
    }
    return false;
  }
};
