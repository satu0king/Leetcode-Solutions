class Solution {
public:
  bool canArrange(vector<int> &arr, int k) {
    vector<int> c(k);
    for (int a : arr)
      c[(a % k + k) % k]++;

    if (c[0] % 2)
      return false;
    if (k % 2 == 0 && c[k / 2] % 2)
      return false;
    int l = 1;
    int r = k - 1;
    while (l < r)
      if (c[l++] != c[r--])
        return false;

    return true;
  }
};
