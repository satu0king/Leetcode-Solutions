class Solution {
public:
  int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2) {
    int ans = 0;
    vector<int> mn(4, INT_MAX);
    for (int i = 0; i < arr1.size(); i++) {
      for (int j = 0; j < 4; j++) {
        int c = i;
        c += j & 1 ? -arr1[i] : arr1[i];
        c += j & 2 ? -arr2[i] : arr2[i];
        mn[j] = min(mn[j], c);
        ans = max(ans, c - mn[j]);
      }
    }
    return ans;
  }
};

// arr1[i] - arr1[j] + arr2[i] - arr2[j] + j - i
// arr1[j] - arr1[i] + arr2[i] - arr2[j] + j - i
// arr1[j] - arr1[i] + arr2[j] - arr2[i] + j - i
// arr1[i] - arr1[j] + arr2[j] - arr2[i] + j - i

// - (arr1[j] + arr2[j]) - (-arr1[i] - arr2[i] + i)  + j
// arr1[j] - arr2[j] - (arr1[i] - arr2[i] + i) +  j
// arr1[j] + arr2[j] - (arr1[i] + arr2[i] + i) + j;
// -arr1[j] - arr2[j]
