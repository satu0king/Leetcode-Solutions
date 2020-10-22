class Solution {
public:
  vector<int> arr;
  int n;
  int get_prod(int l, int r) {
    if (r < l)
      return -1e9;
    int prod = 1;
    for (int i = l; i <= r; i++) {
      prod *= arr[i];
    }
    return prod;
  }
  int get(int l, int r) {
    if (l > r)
      return -1e9;
    int cnt = 0;
    int fir = n + 1, sec = -1;
    for (int i = l; i <= r; i++) {
      if (arr[i] < 0) {
        cnt++;
        sec = max(sec, i);
        fir = min(fir, i);
      }
    }
    if (cnt % 2 == 0) {
      return get_prod(l, r);
    } else {
      return max(get_prod(fir + 1, r), get_prod(l, sec - 1));
    }
  }

  int maxProduct(vector<int> &nums) {
    arr = nums;
    n = nums.size();

    int l = 0;
    int ans = *max_element(nums.begin(), nums.end());
    for (int r = 0; r < n; r++) {
      if (arr[r] == 0) {
        ans = max(ans, get(l, r - 1));
        l = r + 1;
      }
    }
    // cout << l << " " << n - 1 << endl;
    ans = max(ans, get(l, n - 1));
    return ans;
  }
};
