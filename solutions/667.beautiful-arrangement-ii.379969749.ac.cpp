class Solution {
public:
  vector<int> constructArray(int n, int k) {
    int l = 1, r = n;
    vector<int> ans;
    int prev = 1;
    for (int i = 0; i < k - 1; i++) {
      if (prev)
        ans.push_back(l), l++;
      else
        ans.push_back(r), r--;
      prev ^= 1;
    }
    // cout << l <<  " " << r << endl;
    if (!prev) {
      for (int i = k; i <= n; i++) {
        ans.push_back(r);
        r--;
      }
    } else {
      for (int i = k; i <= n; i++) {
        ans.push_back(l);
        l++;
      }
    }
    return ans;
  }
};
