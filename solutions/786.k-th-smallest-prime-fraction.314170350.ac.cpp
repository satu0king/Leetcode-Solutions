

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &nums, int k) {
    int n = nums.size();

    double l = 1.0 * nums[0] / nums[n - 1];
    double r = 1;

    double ep = 1e-5;
    while (l < r) {
      double m = (l + r) / 2;
      int count = 0;
      int j = 0;

      double f = 0;
      vector<int> ans;
      // cout << m << endl;
      for (int i = 0; i < n; i++) {
        while (j < n && 1.0 * nums[i] > m * nums[j])
          j++;
        count += n - j;
        // cout << i << " " << count << endl;
        if (j < n) {
          if (f < 1.0 * nums[i] / nums[j]) {
            ans = {nums[i], nums[j]};
            f = 1.0 * nums[i] / nums[j];
          }

        } else
          break;
      }

      if (count == k)
        return ans;
      else if (count > k)
        r = m;
      else
        l = m;
    }

    throw "Not Found!";
  }
};
