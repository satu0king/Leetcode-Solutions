class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k) {

    int n = cardPoints.size();

    int tot_sum = 0;

    for (int i = 0; i < n; i++) {
      tot_sum += cardPoints[i];
    }

    int l = 0;
    int curr_sum = 0;

    int ans = 0;
    k = n - k;
    for (int r = 0; r < n; r++) {
      curr_sum += cardPoints[r];

      if (r - l + 1 > k) {
        curr_sum -= cardPoints[l];
        l++;
      }
      // cout << r << " " << l <<  " " << curr_sum << endl;
      if ((r - l + 1) == k) {
        ans = max(ans, tot_sum - curr_sum);
      }
    }

    return ans;
  }
};
