class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
    int satisfied = 0;
    int n = grumpy.size();
    for (int i = 0; i < n; i++)
      if (!grumpy[i])
        satisfied += customers[i];

    int ans = satisfied;

    for (int i = 0; i < n; i++) {
      if (grumpy[i])
        satisfied += customers[i];
      if (i - X >= 0 && grumpy[i - X])
        satisfied -= customers[i - X];
      ans = max(ans, satisfied);
    }
    return ans;
  }
};
