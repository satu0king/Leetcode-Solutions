class Solution {
public:
  int minTaps(int n, vector<int> &ranges) {

    vector<int> endpoints(n + 1);

    for (int i = 0; i <= n; i++) {
      int l = max(0, i - ranges[i]);
      int r = min(n, i + ranges[i]);
      endpoints[l] = max(endpoints[l], r);
    }

    int ans = 0;

    int curr_reach = 0;
    int curr_mx = 0;
    for (int i = 0; i <= n; i++) {
      if (i > curr_reach)
        return -1;
      curr_mx = max(curr_mx, endpoints[i]);
      if (i == curr_reach && i != n) {
        ans++;
        curr_reach = curr_mx;
      }
    }

    return ans;
  }
};
