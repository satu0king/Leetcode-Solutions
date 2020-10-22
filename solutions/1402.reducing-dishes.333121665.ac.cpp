class Solution {
public:
  int maxSatisfaction(vector<int> &satisfaction) {
    sort(satisfaction.rbegin(), satisfaction.rend());

    int ans = 0;
    int t = 0;
    int s = 0;
    for (int dish : satisfaction) {
      t += dish;
      s += t;
      ans = max(ans, s);
    }
    return ans;
  }
};
